# EEEN10242 C Programming GitHub Repository

This is the lab activity for the University of Manchester C Programming course.

## Installation

If you are willing to install this repository on a new PC or new directory, please type:
```git
git clone https://github.com/Ashley5478/EEEN10242.git
```

If you are willing to update this repository on a PC with an existing directory, please type the following commands to identify yourself.
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

Note: `git add .` adds new files but does not delete the existing file. `git add -u` stages all the changes and deletions but does not add any new files. This operation is **case sensitive!**

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
**Note**: If you create a local branch, synchronize your project, and then remove the local branch, the old branch in the remote GitHub repository will remain live. You will have to delete the unnecessary branch by using `git push remote -d [RemoteBranchName]` and replace the "[RemoteBranchName]" with the name of the useless branch you have deleted locally.

## Managing Branches
Managing branches is not as straightforward as there are so many options you can use for your command. However, it is useful especially when you want to make changes to existing source code and you don't want to risk losing the original code. You can also accept or reject the collaborators' changes and even merge the codes to the upper branch.

To create the branch:
```git
git branch [YOUR BRANCH NAME]
```
where you put the name of the branch by replacing the square brackets and the text between them. It is highly advisable to use underscores rather than spaces as this would require one to use quotation marks.

To switch the branch you are exploring:
```git
git switch [DESTINATION BRANCH NAME]
```

The default branch of the git is "main" which is the master. Please do not use "master" or any other names if you want to merge the project to the main branch as this would cause some conflicts when merging the files.

You are currently exploring an old branch with bunch of files to "stage" and you want to move/copy to another branch. You wish to move all your workspace to a new branch named [DESTINATION BRANCH NAME] and this can be done by:
```git
git checkout [DESTINATION BRANCH NAME]
```
Make sure the branch DESTINATION is created using `git branch [DESTINATION BRANCH NAME]`. The git checkout simply copies the files from an old branch to a destination branch and then automatically switches the branch you are exploring to the destination one, without typing `git switch [DESTINATION BRANCH NAME]`. Therefore, if you are completely moving the branch, delete the old one after the checkout.
Alternatively, to create a branch, copy all the files to that new branch, and then explore that branch, use
```git
git checkout -b [DESTINATION BRANCH NAME]
```
noting that there is a `-b` string between `checkout` and `[DESTINATION BRANCH NAME]`.

To delete a local branch (Does not remove the branch on GitHub):
```git
git branch -d [localBranchName]
```
(Recommended)
or
```git
git branch --delete [localBranchName]
```

If you want to delete a remote branch on GitHub, use:
```git
git push remote -d [RemoteBranchName]
```

And finally, there is an option for you to revert the changes of your git commit. If you have made a mistake on your recent commit and want to revert to the old commit, use:
```git
git revert HEAD [NUMBER OF STEPS]
```
where [NUMBER OF STEPS] in natural numbers, *optional*, and determines how many commits you want to go backwards.