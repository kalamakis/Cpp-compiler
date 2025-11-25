#!/usr/bin/env bash
set -euo pipefail

# Branch που θες να ενημερώνεται από το dev (default: nick)
TARGET_BRANCH="${1:-nick}"

if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo "❌ Δεν είσαι μέσα σε git repository."
  exit 1
fi

#echo "➡️  git fetch"
git fetch

#echo "➡️  git switch dev"
git switch dev

#echo "➡️  git pull (στο dev)"
git pull

#echo "➡️  git switch $TARGET_BRANCH"
git switch "$TARGET_BRANCH"

#echo "➡️  git merge dev"
git merge dev

echo "your up to date with dev."
