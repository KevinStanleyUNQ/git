#ifndef REPOSITORY_H
#define REPOSITORY_H

struct config_set;

struct repository {
	/* Environment */
	/*
	 * Path to the git directory.
	 * Cannot be NULL after initialization.
	 */
	char *gitdir;

	/*
	 * Path to the common git directory.
	 * Cannot be NULL after initialization.
	 */
	char *commondir;

	/*
	 * Path to the repository's object store.
	 * Cannot be NULL after initialization.
	 */
	char *objectdir;

	/*
	 * Path to the repository's graft file.
	 * Cannot be NULL after initialization.
	 */
	char *graft_file;

	/*
	 * Path to the current worktree's index file.
	 * Cannot be NULL after initialization.
	 */
	char *index_file;

	/*
	 * Path to the working directory.
	 * A NULL value indicates that there is no working directory.
	 */
	char *worktree;

	/* Subsystems */
	/*
	 * Repository's config which contains key-value pairs from the usual
	 * set of config files (i.e. repo specific .git/config, user wide
	 * ~/.gitconfig, XDG config file and the global /etc/gitconfig)
	 */
	struct config_set *config;

	/* Configurations */
	/*
	 * Bit used during initialization to indicate if repository state (like
	 * the location of the 'objectdir') should be read from the
	 * environment.  By default this bit will be set at the begining of
	 * 'repo_init()' so that all repositories will ignore the environment.
	 * The exception to this is 'the_repository', which doesn't go through
	 * the normal 'repo_init()' process.
	 */
	unsigned ignore_env:1;

	/* Indicate if a repository has a different 'commondir' from 'gitdir' */
	unsigned different_commondir:1;
};

extern struct repository *the_repository;

extern void repo_set_gitdir(struct repository *repo, const char *path);
extern void repo_set_worktree(struct repository *repo, const char *path);
extern int repo_init(struct repository *repo, const char *gitdir, const char *worktree);
extern void repo_clear(struct repository *repo);

#endif /* REPOSITORY_H */
