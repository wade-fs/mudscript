inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "金刀門大廳");
	set( "build", 1008 );
  set ("long", @LONG

一進大廳，廳上掛著一赤金盤龍大匾，上頭寫著斗大的四個字『六陽金刀
』。大廳中擺著一張大紫檀木案，一邊是紫檀架子大理石屏風，一邊是三
尺多高的青綠古銅鼎，壁上一塊烏木牌寫著『金門玉戶神仙府』。地下兩
溜十六張楠木圈椅，上頭搭著五彩刻絲石青椅袱。右邊的牆上掛有由王羲
之親筆所題的蘭亭序，左邊則是一塊木板，上面刻有金刀弟子的排行榜，
可用list來看排行榜。



LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"g1-4",
  "west" : __DIR__"g1-5.c",
  "east" : __DIR__"g1-6.c",
]));

  set("objects", ([ /* sizeof() == 1 */
 "/daemon/class/blademan/master_ba.c":1,
]));

  set("light_up", 1);
  set("valid_startroom",1);

  setup();
  call_other("/obj/board/gblade_b.c","????");
}
int valid_leave(object me,string dir)
{
        if(dir=="east"||dir=="west"||dir=="south")
        {
        if(me->query_temp("being-apprentice"))
        return notify_fail("你還在拜師中 , 想去哪裡 ?\n");
        return 1;
        }
}

void init() 
{
        add_action("do_billing","list");
}

int do_billing(string str) 
{
object *user,me,master;
        int i,j;
        switch(str) {
	  case "combat_exp" : i = 0; break;
	  case "force" : i = 1; break;
	  case "gold-blade" : i = 2; break;
	  case "master" : i = 3; break;
	  default: return notify_fail("使用格式: list <種類>\n"
	                              "經驗值(combat_exp)\n"+
				      "內力(force)\n"+
				      "紫金六陽刀  (gold-blade)\n"+
	                              "師承(master)\n\n");
	}
        user = users();
        me = this_player();
        user = filter_array(user,"filter_family",this_object());
	j=sizeof(user);
        switch(i) {
	  case 0 : user=sort_array(user,"sort_exp",this_object());
                   str=sprintf(HIG + "金刀門經驗值排行榜:\n\n" + NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
                   str=sprintf(HIG + "金刀門內力排行榜:\n\n" + NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 2 : user=sort_array(user,"sort_goldblade",this_object());
	           str=sprintf(HIG + "金刀門紫金六陽刀法排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 3 : str=sprintf(HIG + "金刀門師徒關係:\n\n" + NOR);
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
 if(family->query("family/family_name") == "金刀門" && !wizardp(family)) return 1;
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
int sort_goldblade(object man1, object man2)
{
 int i,j;
 i = man1->query_skill("gold-blade");
 j = man2->query_skill("gold-blade");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
