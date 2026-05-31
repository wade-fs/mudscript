//get_rest.c by bss 把犯錯的玩家先抓到監牢裡面去
#include <ansi.h>
#define SYNTAX  "指令格式﹕get_rest 使用者姓名 because 原因\n"
#define GUILTY_ROOM "/open/wiz/guilty_room"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object player,ob;
        string name,reason;

        if(!arg) return notify_fail(SYNTAX);

        if(sscanf(arg,"%s because %s",name,reason)!=2)
                return notify_fail(SYNTAX);

        seteuid(getuid());
        player=find_player(name);
        if(player)
        {
                if(player->is_fighting())
                        return notify_fail(name+"還在戰鬥中，無法逮捕!!\n");
                player->set("have_get_rest",1);
                player->set("startroom",GUILTY_ROOM);
                tell_room(environment(player),HIM"
忽然有兩名神將出現在眾人眼前，對眾人說道:
"+HIY+player->query("name")+HIM+"犯下了滔天大罪，吾等奉命將其抓入天牢之中，聽候審判!!\n"NOR);
                player->move(GUILTY_ROOM);
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
                player->set("have_get_rest",1);
                player->set("startroom",GUILTY_ROOM);
                player->save();
        }
        log_file("static/GET_REST",sprintf("%s 被 %s 抓進天牢because %s\n"
                 ,name,me->query("id"),reason));
        write(name+"這名玩家已經被抓進天牢了!!\n");
        return 1;
}

