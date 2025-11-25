#!/bin/bash

# Normal routine
git fetch
git switch dev
git pull

# Change your name (branch) nick /alex /tasos
git switch alex

# Merge dev into alex
git merge dev
