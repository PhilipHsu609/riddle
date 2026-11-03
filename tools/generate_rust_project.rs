//! Generate rust-project.json (repo root) for rust-analyzer.
//! Every `solve.rs` under the repo becomes one crate.
//!
//! Usage: make rust-project   (run from the repo root)

use std::fs;
use std::path::{Path, PathBuf};
use std::process::Command;

const SKIP_DIRS: [&str; 4] = ["bin", "build", "target", ".git"];

fn find_sysroot_src() -> Option<String> {
    let output = Command::new("rustc").args(["--print", "sysroot"]).output().ok()?;
    let sysroot = String::from_utf8(output.stdout).ok()?;
    let src = PathBuf::from(sysroot.trim()).join("lib/rustlib/src/rust/library");
    src.exists().then(|| src.to_string_lossy().to_string())
}

fn find_solutions(dir: &Path, out: &mut Vec<PathBuf>) {
    let Ok(entries) = fs::read_dir(dir) else { return };
    for entry in entries.flatten() {
        let path = entry.path();
        if path.is_dir() {
            let name = entry.file_name().to_string_lossy().to_string();
            if !SKIP_DIRS.contains(&name.as_str()) {
                find_solutions(&path, out);
            }
        } else if path.file_name().is_some_and(|n| n == "solve.rs") {
            out.push(path);
        }
    }
}

fn main() {
    let root = std::env::current_dir().expect("no current directory");
    let mut solutions = Vec::new();
    find_solutions(&root, &mut solutions);
    solutions.sort();

    if solutions.is_empty() {
        println!("No solve.rs found");
        return;
    }

    let mut json = String::from("{\n");
    if let Some(sysroot) = find_sysroot_src() {
        json.push_str(&format!("  \"sysroot_src\": \"{}\",\n", sysroot));
    }
    json.push_str("  \"crates\": [\n");
    let entries: Vec<String> = solutions
        .iter()
        .map(|p| {
            let rel = p.strip_prefix(&root).unwrap();
            let name = rel.parent().unwrap().to_string_lossy().to_string();
            format!(
                "    {{\n      \"display_name\": \"{}\",\n      \"root_module\": \"{}\",\n      \"edition\": \"2021\",\n      \"deps\": []\n    }}",
                name,
                rel.to_string_lossy()
            )
        })
        .collect();
    json.push_str(&entries.join(",\n"));
    json.push_str("\n  ]\n}\n");

    fs::write(root.join("rust-project.json"), json).expect("failed to write rust-project.json");
    println!("Generated rust-project.json with {} crate(s)", solutions.len());
}
