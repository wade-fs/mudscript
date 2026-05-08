int valid_read(string path, object user, string func) { return 1; }

int valid_write(string path, object user, string func)
{
    string role;
    string *paths;

    if (!user) { return 0; }

    role = user->query_role();

    if (role == "god") { return 1; }

    paths = user->query_write_paths();

    foreach (p in paths) {
        if (strsrch(path, p) == 0) { return 1; }
    }

    return 0;
}
