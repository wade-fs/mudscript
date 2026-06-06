// Room: /open/gsword/room/gsword3-7.c
inherit ROOM;
#include <ansi.h>
int done;
string search();
void create ()
{
    seteuid(getuid());    // 不是說要加這一行嗎?
  set ("short", "藏劍室");
	set( "build", 34 );
  set ("long", @LONG
一入房門 ,你馬上感到寒氣撲面而來 ,略一凝神 ,只見左首一個平台上 ,一個
暗綠色的盒子散發出無比的寒氣 .而右首的牆壁上倒是掛者許許多多燦爛奪目
的寶劍. 兩邊倒是成為明顯的對比.

LONG);


  set("exits", ([ /* sizeof() == 2 */
  "east":"/open/gsword/room/sproom.c"  
]));

  set("light_up", 1);
  set("no_clean_up",1);
   set("search_desc", ([ /* sizeof() == 1 */
  "牆壁" : (: search :),
]));

  setup();
}

 void init()
{
 add_action("open_box","open");
 }
 
  int open_box(string str)
 {
  object me,ob;
  me =this_player();
  if( done== 0 )
      {
				ob=new("/open/gsword/obj/spsword-1.c");
         if(!ob->move(me))
				 {
				    write("你身上的東西太多了。\n");
						return 1;
				 }

         message("system","只見蜀山上空一道紅光劃空而過\n",users());
         message_vision("驚愕之餘 ,那道紅光已漸漸的凝聚在$N手中\n",me);
       }
    
   else
    message_vision("箱內竟是空無一物 ,你不禁呆了一會\n",me);
  done=1;
  return 1;
  } 

string search()
{

if (this_player()->query_temp("swordtime")==1 && this_player()->query("class")=="blademan" && this_player()->query_temp("swordquest/findball")==6)
{
    message_vision("$N到處找來找去﹐找出了出了一顆夜千鳥晶珠並收進口帶中 \n",this_player() );
    this_player()->set_temp("quests/findball1",7);
   new("/open/gsword/obj1/bbladeball.c")->move(this_player());
    return "";
}
	message_vision("$N在書房中翻來覆去 , 結果什麼也沒發現 \n",this_player() );
	return "";
}
