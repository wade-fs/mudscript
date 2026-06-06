// /cmds/std/fslist.c
// 查詢星際網路節點

#include <globals.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg) {
    object fs_d = load_object("/secure/fs_d");
    if (!fs_d) {
        write("無法載入 fs_d。\n");
        return 1;
    }

    mapping muds = fs_d->query_joined_muds();
    if (!muds || sizeof(muds) == 0) {
        write("目前星際網路中沒有發現其他節點。\n");
        return 1;
    }

    write(HIW("【Fantasy Space 星際節點列表】\n"));
    write(sprintf("%-20s %-10s %-20s\n", "Mudlib ID", "狀態", "入口點"));
    write("--------------------------------------------------\n");
    foreach (string id, mapping data in muds) {
        write(sprintf("%-20s %-10s %-20s\n",
            id,
            (data["status"] == "active" ? HIG("連線中") : YEL("未知")),
            (data["entrance"] ? data["entrance"] : "未設定")
        ));
    }
    write("\n輸入 " + CYN("fsgoto <id>") + " 即可連網傳送。\n");
    return 1;
}

string help() {
    return "【fslist】查詢目前可見的星際節點。\n";
}
