// /secure/simul_efun.c
// 共用模擬內建函式 (SimulEfuns)

#include "/include/ansi.h"

string get_name(object ob) {
    if (!ob) return "無名物";

    mixed name = ob->query_name();
    if (!name) name = ob->query("name");
    if (stringp(name)) return name;

    mixed ids = ob->query_id();
    if (stringp(ids)) return ids;
    if (arrayp(ids) && sizeof(ids) > 0) return ids[0];

    string fname = object_name(ob);
    int pos = strsrch(fname, "#");
    if (pos != -1) fname = substr(fname, 0, pos);
    string *parts = explode(fname, "/");
    return sizeof(parts) > 0 ? parts[sizeof(parts)-1] : fname;
}

varargs string select_lang(mixed data, string lang) {
    if (stringp(data)) return data;
    if (!mapp(data)) return to_string(data);

    if (!lang || lang == "0") {
        object ob = previous_object();
        if (ob) lang = ob->query_lang();
        if (!lang || lang == "0") {
            object tp = this_player();
            if (tp) lang = tp->query_lang();
        }
    }

    if (!lang || lang == "0") lang = "en";

    if (data[lang]) return data[lang];
    if (data["en"]) return data["en"];

    mixed ks = keys(data);
    if (sizeof(ks) > 0) return data[ks[0]];
    return "None";
}

mixed *shuffle(mixed *arr) {
    if (!arrayp(arr)) return ({});
    mixed *tmp = copy(arr);
    int i = sizeof(tmp);
    while (i > 0) {
        int j = random(i);
        i--;
        mixed t = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = t;
    }
    return tmp;
}

mixed element_of(mixed *arr) {
    if (!arrayp(arr) || sizeof(arr) == 0) return 0;
    return arr[random(sizeof(arr))];
}

mixed random_element(mixed *arr) {
    return element_of(arr);
}

int in_array(mixed item, mixed *arr) {
    if (!arrayp(arr)) return 0;
    return member_array(item, arr) != -1;
}

varargs int string_in(string str, mixed targets) {
    if (!str || str == "") return 0;
    if (arrayp(targets)) {
        foreach (mixed elem in targets) {
            if (stringp(elem)) {
                if (trim(elem) == trim(str) || lower_case(trim(elem)) == lower_case(trim(str))) return 1;
            } else if (elem == str) {
                return 1;
            }
        }
        return 0;
    }
    if (stringp(targets)) {
        string *parts = explode(targets, ",");
        foreach (string p in parts) {
            if (trim(p) == trim(str) || lower_case(trim(p)) == lower_case(trim(str))) return 1;
        }
    }
    return 0;
}

varargs int strings_in(string str, mixed targets) {
    return string_in(str, targets);
}

varargs int stringsIn(string str, mixed targets) {
    return string_in(str, targets);
}

string _t(string key) {
    string lang = "en";
    object ob = previous_object();
    if (ob) lang = ob->query_lang();
    if (!lang || lang == "0") {
        object tp = this_player();
        if (tp) lang = tp->query_lang();
    }
    if (!lang || lang == "0") lang = "en";

    object ld = find_object("/secure/language_d.c");
    if (!ld) ld = load_object("/secure/language_d.c");
    if (ld) return ld->translate(key, lang);
    return key;
}

string chinese_time() {
    return ctime(time());
}

varargs void message(string category, string msg, mixed target, mixed exclude) {
    if (objectp(target)) {
        tell_object(target, msg);
    } else if (arrayp(target)) {
        foreach (object ob in target) {
            if (objectp(ob)) tell_object(ob, msg);
        }
    } else if (!target) {
        object tp = this_player();
        if (tp) {
            object env = environment(tp);
            if (env) tell_room(env, msg, exclude);
        }
    }
}

varargs string resolv_path(string path, object user) {
    if (!user) user = this_player();
    if (!user) return path;

    if (!path || path == "") {
        string c = user->query_cwd();
        return stringp(c) ? c : "/";
    }
    if (path[0] == '/') return path;
    if (path[0] != '.') path = "./" + path;

    string cwd = user->query_cwd();
    if (!stringp(cwd) || cwd == "") cwd = "/";
    if (cwd[strlen(cwd)-1] != '/') cwd += "/";

    return resolve_path(path, cwd);
}

mapping query_world_manifest() {
    object m = master();
    if (m) {
        mixed res = m->get_world_manifest();
        if (mapp(res)) return res;
    }
    return ([]);
}
