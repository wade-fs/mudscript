/******************************************************************

修改 by kalin 2003-06-16
a.增加list功能

******************************************************************/

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "讀書房");
  set ("long", @LONG
簡單樸實的佈置，讓人在此能放開心胸，靜下自己
的心，好好的讀書，你可以在此小睡一番，恢復一下自
己的精神。左邊則是一塊木板，上面刻有儒門弟子的排
行榜，可用list來看排行榜，也可以look note來認識
儒門。


LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r17.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/obj/iron.c" : 1,
]));
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
"note" : HIY + "\n你可以help 儒門 來獲得儒門的相關介紹。" + NOR,]));

  setup();
}

int valid_leave(object who,string dir)
{
    if( dir == "south" && who->query_temp("sleeping") )
     return notify_fail("去哪裡？你想夢遊啊？\n");
     if( dir == "south" && who->query_temp("sleep") )
                return notify_fail("既然來了就睡(sleep)一下再走吧。\n");
        return ::valid_leave(who,dir);
}

void init()
{
        add_action("do_sleep","sleep");
        add_action("do_look", "look");
        add_action("do_score", "score");
        add_action("do_score", "hp");
        add_action("do_study", "study");
		add_action("do_billing","list");
}

int do_sleep(string arg)
{
        object who;
        who = this_player();
        if( who->query_temp("sleeping") )
        {
                tell_object(who, "你已經睡著了，還想睡到死啊？\n");
                return 1;
        }
        tell_object(who, "你躺在房間裡的小床上，呼呼大睡了起來。\n");
        who->delete_temp("sleep");
        who->set_temp("sleeping", 1);
     call_out("wakeup", 10,who);
        return 1;
}

int wakeup(object who)
{
        tell_object(who, HIC + "一覺醒來，你覺得你的精神稍稍恢復了。\n" + NOR);
    who->receive_heal("sen",100);
        who->delete_temp("sleeping");
        return 1;
}

int do_look()
{
        object who = this_player();

        if( who->query_temp("sleeping") )
        {
                tell_object(who, "要睡覺眼睛就給我乖乖閉著，不要東張西望。\n");
                return 1;
        }
}

int do_score()
{
        object who = this_player();

        if( who->query_temp("sleeping") )
        {
                tell_object(who, "安啦！等睡起來就都好了啦。\n");
                return 1;
        }
}
int do_study()
{
        object who = this_player();

        if( who->query_temp("sleeping") )
        {
                tell_object(who, "安啦！等睡起來就可以讀了啦。\n");
                return 1;
        }
}
//******************************   List   ******************************
int do_billing(string str) {
        object *user,me,master;
        int i,j;
        switch(str) {
          case "combat_exp" : i = 0; break;
          case "force" : i = 1; break;
          case "MKS" : i = 2; break;
          case "movedown" : i = 3; break;
          case "finger" : i = 4; break;
          case "master" : i = 5; break;
          default: return notify_fail("使用格式: list <種類>\n"
                                      "經驗值(combat_exp)\n"+
                                      "內力(force)\n"+
                                      "殺人數(MKS)\n"+
                                      "七星封穴(movedown)\n"+
                                      "儒門幻指(finger)\n"+
                                      "師承(master)\n\n");
        }
        user = users();
        me = this_player();
        user = filter_array(user,"filter_family",this_object());
	j=sizeof(user);
        switch(i) {
          case 0 : user=sort_array(user,"sort_exp",this_object());
	           str=sprintf(HIG + "儒門經驗值排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
	           str=sprintf(HIG + "儒門內力排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 2 : user=sort_array(user,"sort_MKS",this_object());
	           str=sprintf(HIG + "儒門殺人數排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 3 : user=sort_array(user,"sort_movedown",this_object());
                   str=sprintf(HIG + "儒門七星封穴排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
                   tell_object(this_player(),str);
		   break;
	  case 4 : user=sort_array(user,"sort_finger",this_object());
	           str=sprintf(HIG + "儒門儒門幻指排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           tell_object(this_player(),str);
		   break;
	  case 5 : str=sprintf(HIG + "儒門師徒關係:\n\n" + NOR);
                   for(i=0; i<j; i++) {
	              if( user[i]->query("family/master_is_ppl") ) {
	                if( master=find_player(user[i]->query("family/master_id"))) {
	                  if( master->query("name") != user[i]->query("family/master_name"))
		            user[i]->set("family/master_name",master->query("name"));
	                }
	                else {
		          if( master=FINGER_D->acquire_login_ob(user[i]->query("family/master_id"))) {
	                    if( master->query("name") != user[i]->query("family/master_name"))
	                      user[i]->set("family/master_name",master->query("name"));
                            destruct(master);
                          }
	                }
	              }
                      str+=sprintf(HIC + "%|20s(%|10s)     師承  %|20s(%|10s)\n" + NOR,user[i]->query("name"),user[i]->query("id"),user[i]->query("family/master_name"),user[i]->query("family/master_id"));
	           }
                   str+="\n";
   	           tell_object(this_player(),str);
		   break;
        }
	return 1;
}

int filter_family(object family)
{
 if(family->query("family/family_name") == "儒門" && !wizardp(family)) return 1;
 return 0; 
}
int sort_exp(object man1, object man2)
{
 int i,j;
 i = man1->query("combat_exp");
 j = man2->query("combat_exp");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_force(object man1, object man2)
{
 int i,j;
 i = man1->query("max_force");
 j = man2->query("max_force");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_MKS(object man1, object man2)
{
 int i,j;
 i = man1->query("MKS");
 j = man2->query("MKS");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_movedown(object man1, object man2)
{
 int i,j;
 i = man1->query_function("movedown");
 j = man2->query_function("movedown");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_finger(object man1, object man2)
{
 int i,j;
 i = man1->query_function("finger");
 j = man2->query_function("finger");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
