// /secure/command_d.c
// 共用指令守護進程 (Command Daemon)

inherit "/std/object.c";

mapping cmd_map;

int rehash() {
    string *dirs = ({ "/cmds/", "/cmds/admin/" });
    cmd_map = ([]);
    int count = 0;

    mapping mf = query_world_manifest();
    mixed *excluded = (mapp(mf) && arrayp(mf["exclude_cmds"])) ? mf["exclude_cmds"] : ({});

    foreach (string dir in dirs) {
        string *files = get_dir(dir);
        if (!files) continue;

        foreach (string file in files) {
            if (strlen(file) < 3 || substr(file, strlen(file)-2, 2) != ".c") continue;
            if (sizeof(excluded) > 0 && member_array(file, excluded) != -1) continue;

            string full_path = dir + file;
            object cmd_ob = find_object(full_path);
            if (!cmd_ob) cmd_ob = load_object(full_path);
            if (!cmd_ob) continue;

            mixed verbs = cmd_ob->query_verbs();
            if (!verbs || !sizeof(verbs)) {
                string v = file;
                if (strsrch(v, "cmd_") == 0) v = substr(v, 4, strlen(v)-4);
                v = substr(v, 0, strlen(v)-2);
                verbs = ({ v });
            }

            foreach (string v in verbs) {
                cmd_map[v] = full_path;
                count++;
            }
        }
    }
    return count;
}

void create() {
    ::create();
    rehash();
}

int execute(object me, string verb, string arg) {
    if (verb != "alias" && verb != "eval" && ((verb && strsrch(verb, ";") != -1) || (arg && stringp(arg) && strsrch(arg, ";") != -1))) {
        string full_cmd = verb;
        if (arg && stringp(arg) && arg != "") {
            full_cmd = verb + " " + arg;
        }
        string *cmds = explode(full_cmd, ";");
        foreach (string c in cmds) {
            c = trim(c);
            if (c && c != "") {
                me->command(c);
            }
        }
        return 1;
    }

    if (arg == "") arg = 0;

    mixed cmd_file = cmd_map[verb];
    if (cmd_file) {
        object cmd_ob = load_object(cmd_file);
        if (cmd_ob) {
            return cmd_ob->main(me, verb, arg);
        }
    }

    object social_d = load_object("/secure/social_d.c");
    if (social_d && social_d->execute_social(me, verb, arg)) {
        return 1;
    }

    return 0;
}

mapping query_cmd_map() { return cmd_map; }

mapping query_categorized_commands(string lang) {
    mapping res = ([]);
    string *verbs = sort_array(keys(cmd_map), 1);
    object lang_d = find_object("/secure/language_d.c");
    if (!lang_d) lang_d = load_object("/secure/language_d.c");

    foreach (string v in verbs) {
        string file = cmd_map[v];
        object ob = find_object(file);
        if (!ob) ob = load_object(file);

        string cat = "Other";
        if (ob) {
            mixed c = ob->query_category();
            if (stringp(c)) cat = c;
        }
        if (strsrch(file, "/cmds/admin/") == 0) {
            cat = "Admin";
        }

        string cat_key = "cat_" + lower_case(cat);
        string localized_cat = lang_d ? lang_d->translate(cat_key, lang) : cat;
        if (localized_cat == cat_key) localized_cat = cat;

        if (!res[localized_cat]) res[localized_cat] = ({});
        res[localized_cat] += ({ v });
    }
    return res;
}
