#include <ansi.h>
//#define TIME_TICK (time()*60)
#include <localtime.h>

inherit ROOM;

void create()
{
        set("short", HIR"亂世監牢"NOR);
        set("long", @LONG
犯了錯的玩家將在這裡服刑，如果要查詢還有多久出獄請type term。
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
  "up" : "/d/snow/inn",
]));
 set("objects", ([
               "/open/center/npc/jail_soldier" : 2
 ]));

        set("valid_startroom", 1);

//        set_heart_beat(1);
        set("no_fight",1);
        set("no_perform",1);
set("no_study",1);
        set("no_exert",1);
        set("no_recall",1);
                set("no_remember",1);
 setup();
}

void init()
{
        //::init();
        add_action("do_see_term", "term");
        if ( !wizardp(this_player()) ){
                add_action("do_suicide","suicide");
                add_action("do_conjure","conjure");
  add_action("no_comm", "chat");
add_action("no_workroom","matonworkroom");
add_action("no_workroom","kellymaton");
add_action("no_workroom","workroom");
  add_action("do_get","get");
  add_action("no_comm", "chat*");
                add_action("do_move","move");
        }
        //this_player()->set("startroom","/u/o/oaking/jailroom");
}
int valid_leave(object me, string dir)
{
//tell_object(me,me->query("out_jail_time") + dir + me->query("mud_age"));
        if( !wizardp(me) && dir=="up" && (me->query("out_jail_time") > me->query("mud_age")))
                return notify_fail(HIR"你刑期未滿，慢慢熬吧！"NOR"\n");
        else {
                if(me->query("tmp_title")) {
                        me->set("title", me->query("tmp_title"));
                        me->delete("tmp_title");
                  }
                          me->delete("gotojail");
                me->delete("out_jail_time");
          if ((me->query("out_jail_time") > me->query("mud_age"))){
          me->set("startroom","/d/wiz/jailroom");
          }
                return ::valid_leave(me, dir);
        }
}
int do_see_term()
{
        object me;
        int term;
        string msg;
        msg="你的刑期還有";
        me=this_player();
        term = me->query("out_jail_time") - me->query("mud_age");
        if (term<=0) write("你的刑期已滿，自己要好好的革新喔！\n");
        else{
                if ( term/3600 ){
                        msg=msg+HIR+term/3600+"小時"+NOR;
                        term=term%3600;
                }
                if ( term/60 ){
                        msg=msg+HIW+term/60+"分鐘"+NOR;
                }
                if ( term%60 ){
                        msg=msg+HIW+term%60+"秒"+NOR+"\n";
                }
                write(msg+"\n");
        }
        return 1;
}

int do_suicide()
{
        write("想畏罪自殺？休想！\n");
        return 1;
}
int do_comm()
{
write("在監獄不能執行指令。\n");
return 1;
}
int do_workroom()
{
write("就算是區域巫師被關也是一樣。\n");
return 1;
}
int do_conjure()
{
        write("監獄不可以使用法術！\n");
        return 1;
}

int do_move()
{
        write("監獄不可以使用座騎！\n");
        return 1;
}
int do_get(string arg)
{
        object ob,env;
        env=environment(this_player());
        if (arg && (ob=present(arg, env)) ){
                if (ob->is_character()){
                        write("監牢不可背人！\n");
                        return 1;
                }
        }
}

void heart_beat()
{
        object *obj;
        object warden;
        int i;

        if (!(warden=find_living("warden man")) &&
                !(warden=find_object("warden man")))
                return;
        // 沒有人的時候不要做事
        if(sizeof(obj=all_inventory(environment(warden)))<2)
                return;

        for(i=0;i<sizeof(obj);i++){
                if (userp(obj[i]))
                        write(obj[i]->name()+"\n");
        }
}

