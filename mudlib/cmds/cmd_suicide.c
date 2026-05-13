// mudlib/cmds/cmd_suicide.c
// 自殺指令：suicide (徹底刪除角色並備份)

#include "/include/config.h"
#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (arg != "-f") {
        write(HIR("【極度危險】此指令將徹底刪除您的角色資料！\n"));
        write("您的物品將被清空，存檔將被移至備份區，您必須重新註冊才能再次遊戲。\n");
        write("如果您確定要這麼做，請輸入：suicide -f\n");
        return 1;
    }

    write(RED("\n你感覺到生命力正在飛速流逝... 這是一場真正的終結。\n"));
    write(HIW("正在清理物品...\n"));
    
    // 1. 東西全清光
    object *inv = all_inventory(me);
    for (int i = 0; i < sizeof(inv); i++) {
        destruct(inv[i]);
    }

    // 2. 準備備份路徑
    string id = me->get_id();
    string date = strftime("%Y%m%d");
    string old_file = me->query_save_file() + ".o";
    string backup_file = "/data/backup/user/" + id + "_" + date + ".o";

    write(HIW("正在備份角色資料至 ") + backup_file + " ...\n");
    
    // 3. 玩家資料檔移至備份區
    // 先儲存一次最新的 (雖然東西清光了)
    me->save();
    
    if (rename(old_file, backup_file)) {
        write(GRN("備份完成。\n"));
    } else {
        write(RED("備份失敗！但為了安全，我們仍將嘗試刪除原始存檔。\n"));
        rm(old_file);
    }

    write(HIR("再見了，" + me->query_name() + "。希望在另一個輪迴還能見到你。\n"));
    
    // 4. 延遲 3 秒後返回登入畫面 (使用毫秒級 sleep efun)
    write(CYN("\n(系統將在 3 秒後自動返回登入介面...)\n"));
    
    sleep(3000);
    
    object login_ob = clone_object("/std/login.c");
    if (login_ob) {
        if (exec(login_ob, me)) {
            login_ob->logon();
            destruct(me);
            return 1;
        }
    }

    // 若轉移失敗，則執行強制離線
    destruct(me);
    
    return 1;
}

string help() {
    return "【自殺指令】\n" +
           "  suicide -f     徹底刪除當前角色（資料將備份後移除）\n" +
           "\n" +
           "  警告：這不是一般的死亡，這會讓您失去整個角色存檔！\n";
}
