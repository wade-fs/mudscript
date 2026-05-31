//get_rest.c by bss 把玩家從監牢放出來
#include <ansi.h>
#include <login.h>
#define SYNTAX  "指令格式﹕unget_rest 使用者姓名\n"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object player,ob;
        string name,reason;

        if(!arg) return notify_fail(SYNTAX);

        name=arg;
        seteuid(getuid());
        player=find_player(name);
        if(player)
        {
                if(!player->query("have_get_rest"))
                        return notify_fail("他並沒有在天牢裡阿!!\n");
                player->set("have_get_rest",0);
                player->set("startroom",STARTROOM);
                tell_room(environment(player),HIM"
忽然有兩名神將出現在眾人眼前，對眾人說道:吾等奉命釋放
"+HIY+player->query("name")+HIM+"並將其送回人間!!\n"NOR);
                player->move(STARTROOM);
                player->save();
        }
        else
        {
                if(!FINGER_D->acquire_login_ob(name))
                        return notify_fail("沒有這個玩家!!\n");

                ob="/adm/daemons/cappointd.c"->get_user_ob(name);
                player="/adm/daemons/cappointd.c"->get_user_body(ob);
                player->set_temp("link_ob",ob);
                player->setup();
                if(!player->query("have_get_rest"))
                        return notify_fail("他並沒有在天牢裡阿!!\n");
                player->set("have_get_rest",0);
                player->set("startroom",STARTROOM);
                player->save();
        }
        write(name+"這名玩家已經被釋放了!!\n");
        log_file("static/UNGET_REST",sprintf("%s 被 %s 放出天牢 at %s\n"
                 ,name,me->query("id"),ctime(time())));
        return 1;
}

