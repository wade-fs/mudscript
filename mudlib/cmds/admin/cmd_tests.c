// /cmds/admin/cmd_tests.c
// 執行系統自動化測試指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (me->query_role() != "god") {
        write("只有管理員可以使用此指令。\n");
        return 1;
    }

    write(HIW("🚀 開始執行 MudScript 核心功能驗證...\n"));

    string *test_files = ({
        "/tests/test_syntax.c",
        "/tests/test_logic.c",
        "/tests/test_security.c",
        "/tests/test_language.c",
        "/tests/test_quest.c"
    });

    int total = 0;
    int passed = 0;

    foreach (string file in test_files) {
        object test_ob = load_object(file);
        if (!test_ob) {
            write(HIR("❌ 無法載入測試檔案: ") + file + "\n");
            continue;
        }
        
        test_ob->run_tests();
        total += test_ob->query_total();
        passed += test_ob->query_passed();
        
        // 測試完後銷毀，確保下次執行是乾淨的
        destruct(test_ob);
    }

    write(BOLD_WHT("==========================================") + "\n");
    if (passed == total) {
        write(BOLD_GRN("✨ 恭喜！所有核心測試全部通過！(" + passed + "/" + total + ")") + "\n");
    } else {
        write(BOLD_RED("⚠️ 警報！共有 " + (total - passed) + " 個測試項目失敗！") + "\n");
    }
    write(BOLD_WHT("==========================================") + "\n");

    return total - passed; // 回傳失敗次數
}

string help() {
    return "【管理指令】\n" +
           "  tests    執行系統核心功能自動化測試，驗證直譯器正確性\n";
}
