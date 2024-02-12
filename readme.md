# EEEN10242 C Programming GitHub Repository

This is the lab activity for University of Manchester C Programming course.

## Installation

If you are willing to update this repository in a new PC, please type the following commands to identify yourself.
```git
git config --global user.name "Jeong-Hyun Kim"
git config --global user.email "jeong-hyun.kim@student.manchester.ac.uk"
git remote set-url origin https://github.com/Ashley5478/EEEN10242.git
```

## Usage
To download from the GitHub, use
```git
git pull https://github.com/Ashley5478/EEEN10242.git
```
on your command prompt. You may be asked to log in to your GitHub.

## Posting
To undergo "stage changes" and add all the files,
```git
git add -A
```
or
```git
git add *
```

To check your git status,
```git
git status
```

Describe any changes you made:
```git
git commit -m "YOUR TEXT HERE"
```

And then finally, publish it:
```git
git push
```

## Managing Branches
Managing branches are not as straightforward as there are so many options you can use for your command. However, it is useful especially when you want to make changes to existing source code and you don't want to risk losing the original code. You can also accept or reject the collaborators' changes and even merge the codes to the upper branch.

To create the branch:
```git
git branch [YOUR BRANCH NAME]
```
where you put the name of the branch by replacing the square brackets and the text between them. It is highly advisable to use underscores rather than spaces as this would require one to use quotation marks.

To switch the branch you are exploring:
```git
git switch [DESTINATION BRANCH NAME]
```

The default branch of the git is "main" which is the master.

To delete a local branch (Does not remove the branch on GitHub):
```git
git branch -d [localBranchName]
```
or
```git
git branch --delete [localBranchName]
```

If you want to delete a remote branch on GitHub, use:
```git
git push remote -d [RemoteBranchName]
```