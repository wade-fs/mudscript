// reboot.c

#include <login.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string wiz_status;
        object npc;
        int     t;

        if( me != this_player(1) ) return 0;
        
        wiz_status = SECURITY_D->get_status(me);
if( wiz_status!="(manager)" && wiz_status != "(admin)" && wiz_status != "(arch)" && wiz_status !="(guest)")
                return notify_fail("只有 (arch) 以上的巫師才能重新啟動" + MUD_NAME + "\n");

        seteuid(getuid());

        npc = new(NPC_DEMOGORGON);
        npc->move(REBOOT_PLACE);
        if (!arg)
          npc->start_shutdown(15);
        else {
          sscanf (arg, "%d", t);
          npc->start_shutdown(t);
        }
/*
      if (npc = new(NPC_KAWALI)) {
            npc->move("/u/w/wade/workroom");
            npc->do_reboot();

        write("Ok。\n");
      }
      else write ("找不到 " + NPC_KAWALI + "\n");
*/

        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : reboot [分鐘數]
指令說明 :
    本命令會讓系統馬上停止一切動作, 當然, 正常情況下是
    跟當機不一樣, 而是先將玩家的資料存檔, 然後再關機.
    可以在命令後面加個分鐘數, 如果小於 15 分鐘, 那麼
    會每分鐘顯示訊息通知所有人準備好關機動作, 如賣東西
    或存檔等等.
其他參考 :
    shutdown
HELP
  );
  return 1;
}
