@echo off
rem k reads \r as code: keep this clone out of git's CRLF checkout (core.autocrlf), and undo one if it happened
git ls-files --eol 2>nul | findstr /r /c:"i/lf *w/crlf" >nul || (git config core.autocrlf false 2>nul & exit /b 0)
git diff --quiet && git diff --cached --quiet || (echo eol: files were checked out with CRLF; commit or stash your changes, then rerun & exit /b 1)
git config core.autocrlf false && git rm -rq --cached . && git reset -q --hard && echo eol: checked out again with LF
