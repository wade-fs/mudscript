// cmds/admin/cmd_tests.c - MUD_TEST_MODE 測試指令 (通用)

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (me->query_role() != "god" && me->query_role() != "wizard") {
        write("你沒有執行測試的權限。\n");
        return 1;
    }

    write("{HIW}===== MUD 自動化測試 ====={NOR}\n");

    int total_pass = 0;
    int total_fail = 0;

    // 掃描世界層 /tests/*.c
    mixed *files = get_dir("/tests/*.c");
    if (arrayp(files)) {
        for (int i = 0; i < sizeof(files); i++) {
            string fname = files[i];
            if (!stringp(fname)) continue;
            string fpath = "/tests/" + fname;
            if (file_size(fpath) <= 0) continue;

            object tc = load_object(fpath);
            if (!tc) {
                write("{RED}[ERROR] 無法載入: " + fpath + "{NOR}\n");
                total_fail++;
                continue;
            }

            int f = tc->run_tests();
            total_pass += tc->query_pass_count();
            total_fail += f;
        }
    }

    // 也掃描 /tests/test_manifest.json（若存在）
    if (file_size("/tests/test_manifest.json") > 0) {
        string raw = read_file("/tests/test_manifest.json");
        if (raw && raw != "") {
            mixed data = json_decode(raw);
            if (mapp(data) && arrayp(data["tests"])) {
                mixed *tests = data["tests"];
                for (int i = 0; i < sizeof(tests); i++) {
                    string tpath = tests[i];
                    if (!stringp(tpath)) continue;
                    if (file_size(tpath) <= 0) continue;
                    object tc = load_object(tpath);
                    if (!tc) {
                        write("{RED}[ERROR] 無法載入: " + tpath + "{NOR}\n");
                        total_fail++;
                        continue;
                    }
                    int f = tc->run_tests();
                    total_pass += tc->query_pass_count();
                    total_fail += f;
                }
            }
        }
    }

    write("{HIW}═══════════════════════════{NOR}\n");
    if (total_fail == 0) {
        write("{GRN}✨ 全部通過！(" + total_pass + "/" + (total_pass + total_fail) + "){NOR}\n");
    } else {
        write("{RED}❌ 失敗 " + total_fail + " 個，通過 " + total_pass + " 個{NOR}\n");
    }

    return total_fail;
}
