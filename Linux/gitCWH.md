# Learnings

## Commands

- `git init` to initialize the git in a folder, now your folder becomes git enabled
- `git add <file>` moves the file from *working directory* to *staging area*
- `git add .` moves all the files from *working directory* to *staging area*
- `git config --global user.name "<user_name>"` tells git who is the author
- `git config --global user.email "<user_mail>"` tells the author mail, so that anyone can contact the author
- `git commit -m "Commit message"` changes from *staging area* moves to *local repo* git takes snapshot at current point and records all the changes made, from any commit you can go to any commit and see how the repo was at that moment
- `git log` lists all the commits with info like commit hash, author, Date and commit message
- `git log --oneline` shows the all the commits in concise manner one line for one commit showing partial hash and commit message
- `git restore --staged <file>` unstage the file, moves file from *staging area* back to *working directory*
- `git restore <file>` discards all the changes made in *working directory*
- `git rm .env` removes the file from your computer and Git.
- `git rm --cached .env` removes it only from Git's tracking. The file stays on your machine.
- `git branch <branch>` creates a new branch of given name
- `git branch` lists all the branches, with * showing the current branch
- `git switch <branch>` switches current *working directory* to that branch
- `git merge <branch>` merges the current branch to the given branch
- `git branch -d <branch>` deletes the given branch
- `git switch -c <branch>` creates new branch & switches to it
- `git stash` stores changes from *working directory* temporarily into stash, multiple stash points can be created and take out stashes as you wish, stash are used to make *working directory* clean and do other urgent work on it temporarily
- `git stash list` lists all the stashes made
- `git stash pop` brings back all the changes which were stashed to *working directory*, empties stash
- `git stash apply` while keeping changes in stash, brings back all the changes which were stashed to *working directory*, stash is not empty
- `git tag` lists all the tags
- `git tag <tag_name>` Creates a lightweight tag of given name
- `git tag -a <tag_name> -m "msg"` Creates an annotated tag
- `git show <tag_name>` Shows tag details
- `git rebase <branch>` rebases current branch onto the given branch, replays current branch commits on given branch

## Files

- `.gitignore` file is used to tell git which files not to track, it can take file name, directory, file type, etc.
- `.gitkeep` git doesn't tracks empty folders so to track empty folders this file is added

## Doubts

### There's a file already being tracked by git, I later wants git to stop tracking it, but adding it in .gitignore file doesn't do anything

- Git only prevents Git from tracking new, untracked files. It does not stop tracking files that are already being tracked.

### Fix

```bash
# Tell Git to stop tracking the file without deleting it from your computer:
git rm --cached .env
# Then commit the change:
git commit -m "Stop tracking .env"
```

### **Important**

- `git rm .env` → removes the file from your computer and Git.
- `git rm --cached .env` → removes it only from Git's tracking. The file stays on your machine.
- If the .env contained sensitive information (API keys, passwords, tokens, etc.), adding it to .gitignore is not enough. Those secrets are still present in the repository's history.

## Notes

### 1. Branching best practices

- Use one branch only to implement one feature, not do all the work in it
- Never do development on *main branch*, keep it stable
- Delete the branch once it's merged
- Use meaning-ful branch names
- Branches should be short-lived, merge asap to reduce risks and conflicts

### 2. In which branch to merge/rebase master or feature?

### 3. `git rebase` Use/Explanation

```text
Initial history

A -- B -- C -- F -- G   (master)
           \
            D -- E       (feature)
```

While on `feature`, we run:

```bash
git rebase master
```

Git takes the commits unique to `feature` (`D` and `E`), temporarily removes them, moves the `feature` branch to `G`, and then reapplies those commits as new commits `D'` and `E'`.

The history becomes:

```text
Initial history

A -- B -- C -- F -- G   (master)
                     \
                      D' -- E'    (feature)
```

Which becomes a single branch instead of 2 branches, with `master` behind the `feature`

```text
A -- B -- C -- F -- G -- D' -- E'
                    ↑          ↑
                  master    feature
```

Notice that **there isn't really a branch split anymore**. (Technically, there are still two branch pointers—`master` and `feature`—but they both point to commits on the same linear history.)

Now we switch to `master` and run:

```bash
git merge feature
```

Git sees that `master` is an **ancestor** of `feature`. Since all of `master`'s commits are already part of `feature`'s history, Git doesn't need to combine two histories. It simply **fast-forwards** the `master` pointer to `feature`.

The final history is:

```text
A -- B -- C -- F -- G -- D' -- E'
                              ↑
                      master, feature
```

No merge commit is created because Git didn't have to merge two divergent histories—it only moved the `master` branch pointer forward.

Now both `master` & feature `points` to same commit
