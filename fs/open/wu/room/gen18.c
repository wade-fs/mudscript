inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  seteuid(getuid());    // 不是說要加這一行嗎?
        set("short",CYN + "地牢" + NOR);
	set( "build", 12 );
        set("long", @LONG
你走進一間陰暗潮濕的小房間，剛進房間時你覺得一片漆黑，等你
眼睛慢慢習慣黑暗後，你赫然發覺有個人被鎖在這裡，他四肢被鐵鍊鎖
住，琵琶骨也被鐵鍊貫穿，他低著頭動也不動，令你不知他是死是活..
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/wu/room/gen17",
]));
  set("light_up", 1);
  set("no_transmit",1);
  set("no_auc",1);
  set("need_key/south",1);
  create_door("south",HIB + "藍色鐵門" + NOR,"north",DOOR_LOCKED);
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/obj/ya1" : 1,
]));
  setup();
}
void init()
{
 add_action("free_ya","free");
}

int free_ya(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("ya",environment(ob)))
    return notify_fail("人去樓空了，你還放什麼。\n");
  if( str!="ya")
    return notify_fail("你要釋放誰呀。\n");
  if( ob->query("force") > 1500)
  {
  message_vision(HIW + "$N運起全身內力扯斷" + HIC + "寒冰鐵鍊" + HIW + ".........\n" + NOR,ob);
  ob->set("get_head",1);
  write("\n");
     ob1=present("ya",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  return 1;
  }
  else
  {
   message_vision(HIW + "$N運起內力想要扯斷" + HIC + "寒冰鐵鍊" + NOR + "，由於內力不足被鐵鍊上的寒氣所侵!!\n" + NOR,ob);
   ob->add("kee",-250);
   return 0;
  }
}
int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision("只見葉狂運起內力，身上發出爆裂般的聲音\n",ob);
  call_out("msg2",3,ob);
  return 1;
}
int msg2()
{
object freeer=this_player();
  message_vision("葉狂道: 小子謝謝你啦.....\n\n",freeer);
  message_vision("葉狂雙手向上一擊，轟的一聲!!地牢上方被打出一個大洞，走了出去。\n", freeer) ;
  set("exits/up","/open/ping/room/road4");
/*  
  ob1=new("/open/wu/npc/ya");
  ob1->move("/open/main/room/m11");
  ob1->set("get_head",1);
*/
  message("mud",HIC + "只見"HIW+freeer->query("name")+HIC"突破重重難關,以本身修為震開了葉狂的寒冰鐵鍊\n\n" + NOR,users());
  message("mud",HIC + "葉狂大聲吼道:" + HIW + "我自由了!!我自由了!!復仇的時刻終於來臨了\n\n" + NOR,users());
  call_out("msg3",3,freeer);
  return 1;
}
int msg3(object ob)
{
object ob1;
ob1=new("/open/wu/npc/ya");
ob1->move("/open/main/room/m11");
ob1->set("get_head",1);

 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom1");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom1");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom2");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom2");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom2");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom2");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom3");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom3");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom3");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom4");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom4");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom7");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom7");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom7");
 new("/open/wu/npc/badnit")->move("/open/wu/room/luroom4");
 message("mud",HIC + "\n杜 殺吼道:" + HIW
               "惡人谷的囉囉們～～～將瀧山從武林中除名吧！！！\n" + NOR,users());
  call_out("msg4",3,ob);
  return 1;
 }
int msg4(object ob)
{
message("mud",HIR + "\n鄭士欣嘆道:
         誰可以挽救這武林浩劫呢？？？\n\n" + NOR,users());
  return 1;
}
