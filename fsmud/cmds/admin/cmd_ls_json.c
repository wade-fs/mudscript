// /cmds/admin/cmd_ls_json.c
inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!wizardp(me)) return 0;

    if (!arg || arg == "") arg = "/";
    if (arg[0] != '/') arg = "/" + arg;

    mixed *files = get_dir(arg, -1);
    if (!files) {
        if (is_web_client(me)) {
            write(sprintf("{\"ui\": \"ls\", \"path\": \"%s\", \"data\": []}\n", arg));
        } else {
            write("Directory not found or empty.\n");
        }
        return 1;
    }

    if (is_web_client(me)) {
        // files 是 ({ ({ name, size, mtime }), ... })
        write(sprintf("{\"ui\": \"ls\", \"path\": \"%s\", \"data\": %s}\n", arg, json_encode(files)));
        return 1;
    }

    // CLI mode
    foreach(mixed *f in files) {
        write(sprintf("%-20s %10d %d\n", f[0], f[1], f[2]));
    }
    return 1;
}

string help() {
    return "Usage: ls_json <path>\nLists directory contents in JSON format for the Web IDE.\n";
}
