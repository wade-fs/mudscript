// daemon/schema_d.c - 世界體系 Schema 守護進程 (Phase 2 MVVM)
// 載入 worlds/<id>/schema/*.json，註冊力量體系／幣制／屬性公式
// 完全世界觀中立，透過 JSON 注入

#include "/include/config.h"

inherit "/std/object.c";

mapping schemas;        // schema_id -> mapping
mapping currency_defs;  // 幣制定義
mapping stat_formulas;  // 屬性公式
mapping power_systems;  // 獨立力量體系表
string  world_id;       // 當前世界識別

string query_save_file() { return "/data/schema_d"; }

void load_schemas();

void create() {
    ::create();
    schemas       = ([]);
    currency_defs = ([]);
    stat_formulas = ([]);
    power_systems = ([]);
    world_id      = "";
    load_schemas();
}

void load_schemas() {
    if (file_size("/manifest.json") > 0) {
        string raw = read_file("/manifest.json");
        if (raw && raw != "") {
            mixed m = json_decode(raw);
            if (mapp(m) && m["world_id"]) world_id = m["world_id"];
        }
    }

    mixed *files = get_dir("/schema/*.json");
    if (!arrayp(files)) return;

    for (int i = 0; i < sizeof(files); i++) {
        string fname = files[i];
        if (!stringp(fname) || strlen(fname) < 6) continue;
        if (fname[sizeof(fname)-5..] != ".json") continue;
        string fpath = "/schema/" + fname;
        if (file_size(fpath) <= 0) continue;

        string raw = read_file(fpath);
        if (!raw || raw == "") continue;
        mixed data = json_decode(raw);
        if (!mapp(data)) continue;

        string sid = fname[..sizeof(fname)-6];
        if (stringp(data["id"]) && data["id"] != "") sid = data["id"];
        schemas[sid] = data;

        string dtype = stringp(data["type"]) ? data["type"] : "";
        if (dtype == "currency") {
            currency_defs[sid] = data;
        } else if (dtype == "stat_formula") {
            stat_formulas[sid] = data;
        } else if (dtype == "power_system") {
            power_systems[sid] = data;
        }
    }
}

mapping query_schema(string sid)        { return schemas ? schemas[sid] : 0; }
mapping query_all_schemas()             { return schemas ? schemas : ([]); }
mapping query_currency_defs()           { return currency_defs ? currency_defs : ([]); }
mapping query_power_systems()           { return power_systems ? power_systems : ([]); }
mapping query_power_system(string sid)  { return power_systems ? power_systems[sid] : 0; }
string  query_world_id()                { return world_id; }

// 查詢指定力量體系與等級對應的境界名稱
string query_realm_for_level(string sys_id, int lv) {
    mapping ps = 0;
    if (sys_id && sys_id != "" && power_systems) {
        ps = power_systems[sys_id];
    } else if (power_systems && sizeof(power_systems) > 0) {
        string *pkeys = keys(power_systems);
        ps = power_systems[pkeys[0]];
    }
    if (!ps || !arrayp(ps["realms"])) return "Lv." + lv;

    mixed *realms = ps["realms"];
    string matched = "Lv." + lv;
    for (int i = 0; i < sizeof(realms); i++) {
        mapping r = realms[i];
        if (!mapp(r)) continue;
        int min_lv = intp(r["min_level"]) ? r["min_level"] : 1;
        int max_lv = intp(r["max_level"]) ? r["max_level"] : 999999;
        if (lv >= min_lv && lv <= max_lv) {
            matched = r["name"] ? to_string(r["name"]) : matched;
            break;
        }
    }
    return matched;
}

// 查詢力量體系自訂屬性標籤
mapping query_stat_labels(string sys_id) {
    mapping ps = 0;
    if (sys_id && sys_id != "" && power_systems) {
        ps = power_systems[sys_id];
    } else if (power_systems && sizeof(power_systems) > 0) {
        string *pkeys = keys(power_systems);
        ps = power_systems[pkeys[0]];
    }
    if (ps && mapp(ps["stat_labels"])) return ps["stat_labels"];
    return ([
        "str": "力量", "con": "體質",
        "int": "智力", "spi": "精神",
        "dex": "敏捷", "per": "感知"
    ]);
}

// 格式化金幣顯示（支援多面額 denominations 或單一 unit）
string format_money(int amount) {
    string *cids = currency_defs ? keys(currency_defs) : ({});
    if (!cids || sizeof(cids) == 0) {
        return amount + " 元";
    }
    mapping primary = 0;
    for (int i = 0; i < sizeof(cids); i++) {
        mapping c = currency_defs[cids[i]];
        if (c && c["primary"]) { primary = c; break; }
    }
    if (!primary) primary = currency_defs[cids[0]];

    if (arrayp(primary["denominations"]) && sizeof(primary["denominations"]) > 0) {
        mixed *denoms = primary["denominations"];
        int rem = amount;
        string res = "";
        for (int i = 0; i < sizeof(denoms); i++) {
            mapping d = denoms[i];
            if (!mapp(d) || !intp(d["value"]) || d["value"] <= 0) continue;
            int cnt = rem / d["value"];
            rem = rem % d["value"];
            if (cnt > 0) {
                if (res != "") res += " ";
                res += cnt + " " + (d["name"] ? d["name"] : "");
            }
        }
        if (res != "") return res;
        mapping last = denoms[sizeof(denoms)-1];
        return "0 " + (mapp(last) && last["name"] ? last["name"] : "元");
    }

    string unit = primary && primary["unit"] ? primary["unit"] : "元";
    return amount + " " + unit;
}

int calc_stat(string formula_id, mapping params) {
    mapping fml = stat_formulas[formula_id];
    if (!fml) return 0;
    int base = fml["base"] ? fml["base"] : 0;
    string primary_stat = fml["primary_stat"] ? fml["primary_stat"] : "";
    int mult = fml["multiplier"] ? fml["multiplier"] : 1;
    int stat_val = mapp(params) && params[primary_stat] ? params[primary_stat] : 0;
    return base + stat_val * mult;
}

void reload() {
    schemas       = ([]);
    currency_defs = ([]);
    stat_formulas = ([]);
    power_systems = ([]);
    load_schemas();
    write("[schema_d] Schema 已重新載入 (" + sizeof(keys(schemas)) + " 個)\n");
}
