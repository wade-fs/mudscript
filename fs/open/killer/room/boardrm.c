#include <room.h>
#include <ansi.h>
inherit ROOM;
 void create()
{
  set("short", "殺手報報室");
	set( "build", 12 );
  set("long", @LONG
           -------  給我報報，我給你全世界  --------
       殺手總壇，目前擴建中。如果有任何蟲蟲，請儘速回報。
       如果蟲蟲夠大隻的話，天才小渡會透露一些總壇資料。
       呵。。。總壇是為殺手設計的。請好康的，不要亂說出去。
       不然被迫改掉，我可不管。大家請在此留言.....
       在一旁的(sign）似乎有記載一些事物
       有任何問題的殺手，請打 help killer 會有說明檔
       打list 可以列出來目前線上的殺手排行榜。
       打want 可以查出目前線上被通緝的殺手全力追殺的人頭

LONG);
        set("exits", ([ /* sizeof() == 1 */
            "north":__DIR__"r0.c",
            "south":__DIR__"floorm.c",
  ]));
set("item_desc", ([ /* sizeof() == 2 */
  
    "sign" : "想消除殺手全力追殺的人頭者，可向葉秀殺問(血的試煉)\n",
   ]));
       setup();
        call_other("/obj/board/killerwizs_b","???");
}
int valid_leave(object me, string dir)
{
  if (me->query("class")!="killer" && dir=="north")
 return notify_fail("這是殺手的禁地!由於你沒練霸雨螫魂,故你無法進入!\n");

return ::valid_leave(me,dir);
}
void init()
{
  add_action("do_pass","pass");
  add_action("do_billing","list");
  add_action("do_check","want");
}
int do_pass()
{
  object me;
  me = this_player();
  me->move("/open/center/room/inn");
  return 1;
}

int do_billing(string str) 
{
        object *user,me,master;
        int i,j;
	switch(str) {
	  case "combat_exp" : i = 0; break;
	  case "rain-throwing" : i = 1; break;
	  case "manakee" : i = 2; break;
	  case "shadow-kill" : i = 3; break;
	  case "force" : i = 4; break;
	  case "master" : i = 5; break;
	  default: return notify_fail("使用格式: list <種類>\n"
		                      "經驗值(combat_exp)\n"+
		                      "魔氣殺(manakee)\n"+
		                      "閻影匕首(shadow-kill)\n"+
		                      "霸雨遮魂(rain-throwing)\n"+
		                      "內力(force)\n"+
		                      "師承(master)\n\n");
	}
        user = users();
        me = this_player();
        user = filter_array(user,"filter_family",this_object());
	j=sizeof(user);
	switch(i) {
	  case 0 : user=sort_array(user,"sort_exp",this_object());
                   str=sprintf(HIG"黑牙聯經驗值排行榜:\n\n"NOR);
	           for(i=0; i<j; i++)
                      str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
		   tell_object(this_player(),str);
	           break;
	  case 1 : user=sort_array(user,"sort_rain",this_object());
	           str=sprintf(HIG"黑牙聯霸雨遮魂排行榜:\n\n"NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
                   break;
	  case 2 : user=sort_array(user,"sort_manakee",this_object());
	           str=sprintf(HIG"殺手魔氣殺等級排行榜:\n\n"NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
                   break;
	  case 3 : user=sort_array(user,"sort_shadow",this_object());
                   str=sprintf(HIG"黑牙聯閻影匕首排行榜:\n\n"NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
		   tell_object(this_player(),str);
                   break;
	  case 4 : user=sort_array(user,"sort_force",this_object());
	           str=sprintf(HIG"黑牙聯內力排行榜:\n\n"NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
	           break;
	  case 5 : str=sprintf(HIG"黑牙聯師徒關係:\n\n"NOR);
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
                      str+=sprintf(HIC"%|20s(%|10s)     師承  %|20s(%|10s)\n"NOR,user[i]->query("name"),user[i]->query("id"),user[i]->query("family/master_name"),user[i]->query("family/master_id"));
	           }
	           str+="\n";
		   tell_object(this_player(),str);
	           break;
	}
        return 1;	
}
//query_function("manakee");
int do_check(string str)
{
    object *user,me,cme,croom;

    int i,j;

    user = users();
    me = this_player();
        
        if (!str)
        {
	user = filter_array(user,"filter_killerwant",this_object());
        j=sizeof(user);
        str=sprintf(HIG"殺手全力追殺的人頭通緝榜:\n\n"NOR);
        for(i=0; i<j; i++)
        {
                        cme=find_player(user[i]->query("id"));
                        croom=environment(cme);
              str+=sprintf(HIC"%2d 號 %s(%s) 在 %-18s \n"NOR,i+1,user[i]->query("name"),user[i]->query("id"),croom->query("short") );
        }
        str+="\n";
	tell_object(this_player(),str);
        return 1;
        }
        return notify_fail("不要亂加指令啦，後面無需要加字串\n");
}
int filter_family(object family)
{
  if(family->query("class") == "killer" && !wizardp(family)) return 1;
  return 0; 
}

int filter_killerwant(object want)
{
//              if(user[i]->query("title") == HIR"殺手全力追殺的人頭"NOR)
  if(!wizardp(want) && want->query("killyar") == 1) return 1;
  return 0; 
}
int sort_exp(object man1, object man2)
{
  int i,j;
  i=man1->query("combat_exp");
  j=man2->query("combat_exp");
  if (i>j) return -1;
  else if (i<j) return 1;
  else return 0;
}
int sort_rain(object man1, object man2)
{
 int   i, j;
 i =  man1->query_skill("rain-throwing",1);
 j =  man2->query_skill("rain-throwing",1);
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_manakee(object man1, object man2)
{
 int   i, j;
 i =  man1->query("functions/manakee/level");
 j = man2->query("functions/manakee/level");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_shadow(object man1, object man2)
{
 int i, j;
 i =  man1->query_skill("shadow-kill",1);
 j = man2->query_skill("shadow-kill",1);
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_force(object man1, object man2)
{
 int i, j;
 i =  man1->query("max_force");
 j = man2->query("max_force");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
