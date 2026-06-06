//by Casey
inherit ROOM;
#include <room.h>
#include <ansi.h>
int be_free=0;

void create ()
{
  seteuid(getuid());   
        set("short",MAG"地底牢籠"NOR);
	set( "build", 262 );
        set("long", @LONG
你來到一間漆黑無比的房間，空氣中全是瀰漫著腐屍和膿血的味道
一不留神被地上的東西所拌倒，你點起火把一看卻倒抽了好幾口寒氣
原來竟是一對龍爪，但它看起來一動也不動，不知道其死活...
LONG
        );       
  set("light_up", 1);
 set("evil", 1);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"f-5",
 "east" : __DIR__"f-1",
 "west" : __DIR__"f-6",

]));
  set("no_transmit",1);
  set("no_auc",1);
 set("objects", ([ /* sizeof() == 1 */
  "/open/mogi/dragon/obj/dragon-1" : 1,
]));
  
  setup();
}
void init()
{
 add_action("free_dragon","free");
}

void reset() { be_free = 0; ::reset(); }
int free_dragon(string str)
{
  object ob,ob1;
  ob=this_player();
   if(!present("stone golden dragon",environment(ob)))
    return notify_fail("什麼東西都沒有，你想做什麼。\n");
  if( str!="dragon"  )
    return notify_fail("你要釋放啥呀。\n");
if(be_free == 1) return notify_fail("什麼東西都沒有，你想做什麼。\n");
  if( ob->query("force") > 1500)
 {
  message_vision(HIW"$N運起全身內勁震碎"HIB"玄鐵鎖銬\n"NOR,ob);
be_free = 1;
ob->set("kill_dragon",1);
  write("\n");
      ob1=present("stone golden dragon",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  return 1;
  }
  else
  {
   message_vision(HIW"$N運起內勁想要震碎"HIB"玄鐵鎖銬"HIW"，由於內力
不足反而被鎖銬震傷!!\n"NOR,ob);
   ob->add("kee",-150);
   return 0;
  }
}
int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision(HIM"\n只見黃金甲龍鱗片鼓張 ,早已死絕的眼神突然間爆射出精光\n"NOR,ob);
  call_out("msg2",3,ob);
  return 1;
}
int msg2(object ob)
{
  object ob1;
  message_vision(HIY"\n黃金甲龍狂吼了一聲 ,緩緩的立起龐大的身軀\n"NOR,ob);
 
  
  ob1=new("/open/mogi/dragon/npc/dragon-gold");
  {
    string *f = ({ "0","1","2","5","6","7"});
    ob1->move("/open/mogi/dragon/f-"+f[random(sizeof(f))]);
  }
  ob1->set("kill_dragon",1);
  if(ob1) 
  {
   message("mud",HIB"\n\n  大地劇烈震動 ,海水翻騰不已 ,天劫來臨了 ...\n\n\n\n"NOR,users());
   call_out("msg3",3,ob,ob1);
  }
  return 1;
}
int msg3(object ob,object ob1)
{ 
  if(ob1)
  { 
   message("mud",HIR"    自遙遠"CYN"魔界"HIR"傳來的陣陣驚人吼聲 ,人們開始慌亂...\n
          地上的鳥獸到處流竄 ,世界當真已走到盡頭了?!\n\n\n"NOR,users());
   call_out("msg4",3,ob,ob1);
  }
  return 1;
 }
int msg4(object ob,object ob1)
{
  if(ob1) message("mud",HIW"\n  地上颳起了一陣陣的"+HIB+"狂風"+HIW+" ,空中一道道"+HIB+"電光"+HIW+"交加不息...\n
  家園被洪水沖走的人們正默默的祈導著 ,遠赴魔界的"+HIY+"勇者"+HIW+"呀...\n"NOR,users());
  return 1;
}



