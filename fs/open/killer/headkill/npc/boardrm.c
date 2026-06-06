#include <room.h>
#include <ansi.h>
inherit ROOM;
 void create()
{
  set("short", "殺手報報室");
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
        object *user,me;
        int i,j,k;

        user = users();
        me = this_player();

        for(i=j=0; i<sizeof(user); i++)
           if(user[i]->query("class") == "killer" && !wizardp(user[i]))
              user[j++] = user[i];

        if(str == "combat_exp") 
		{
           call_out("do_exp",0,user,j);
           return 1;
        }
        else if(str == "rain-throwing") 
		{
           call_out("do_rain",0,user,j);
           return 1;
        }
	else if(str == "manakee") 
		{
           call_out("do_makee",0,user,j);
           return 1;
        }
        else if(str == "shadow-kill") 
		{
           call_out("do_shadow",0,user,j);
           return 1;
        }
        else
           return notify_fail("使用格式: list <種類>\n"
                              "經驗值(combat_exp)\n"+
			      "魔氣殺(manakee)\n"+	
                              "閻影匕首(shadow-kill)\n"+
                              "霸雨遮魂(rain-throwing)\n\n");
}
//query_function("manakee");
int do_check(string str) 
{
    object *user,me,cme,croom;
    int i,j,k;

    user = users();
    me = this_player();
	
	if (!str)
	{
    	for(i=j=0; i<sizeof(user); i++)
      		if(user[i]->query("title") == HIR"殺手全力追殺的人頭"NOR)
          		user[j++] = user[i];
        printf(HIG"\t\t殺手全力追殺的人頭通緝榜:\n\n"NOR);
        for(i=0; i<j; i++)
        {
			cme=find_player(user[i]->query("id"));
			croom=environment(cme);
           tell_object(this_player(),
              sprintf(HIC"\t%2d 號 %s(%s) 在 %-18s \n"NOR,i+1,
                      user[i]->query("name"),
                      user[i]->query("id"),
						croom->query("short") ) );
		 }
        printf("\n");
return 1;
	}
	return notify_fail("不要亂加指令啦，後面無需要加字串\n");
}

int do_exp(object *user,int j) 
{
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if(user[k]->query("combat_exp") > user[i]->query("combat_exp")) {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

        printf(HIG"\t\t黑牙聯經驗值排行榜:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t第%2d名       %-18s %s(%s) \n"NOR,i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));

        printf("\n");
}

int do_makee(object *user,int j) 
{
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if(user[k]->query_function("manakee") > user[i]->query_function("manakee")) {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

        printf(HIG"\t\t殺手魔氣殺等級排行榜:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t第%2d名       %-18s %s(%s) \n"NOR,i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));

        printf("\n");
}

int do_rain(object *user,int j) {
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if(user[k]->query_skill("rain-throwing",1) > 
					user[i]->query_skill("rain-throwing",1)) 
				{
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

        printf(HIG"\t\t黑牙聯霸雨遮魂排行榜:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t第%2d名       %-18s %s(%s) \n"NOR,
                      i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));

        printf("\n");
}

int do_shadow(object *user,int j) {
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if((int)user[k]->query_skill("shadow-kill",1) > 
					(int)user[i]->query_skill("shadow-kill",1)) 
			   {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

        printf(HIG"\t\t 黑牙聯閻影匕首排行榜:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t第%2d名       %-18s %s(%s) \n"NOR,
                      i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));
        printf("\n");
}
