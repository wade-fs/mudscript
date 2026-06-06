
inherit ROOM;
void create()
{
set("short", "會議室");
set("long", @LONG
    這裡是反亂軍的會議室﹐在你面前有一長圓桌上面擺
滿了一些文件和地圖﹐在圓桌正對面有一座位是用黃金打
造的﹐非常的耀眼～在東面牆上佈滿了武器﹐似乎好像要
常常出外打戰﹐在武器(weapon)後方好像有一扇門﹐充滿
了神祕感。。。

LONG
);
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r29.c",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "weapon" : "一把超大型兵器,在他後面好像有東西(things)。\n",
  "things" : "你看了一下..在考慮要不要把兵器翻開(turn)。。。\n",     
]));


setup();
}

void init()
{
  add_action("do_turn", "turn");
}

int do_turn(string arg)
{
object me;
me=this_player();
if(me->query("class")!="soldier")
return notify_fail("只有職業傭兵能用。\n");
message_vision("$N你把武器翻來翻去終於出現了一個門。\n", me);
message_vision("$N順勢推開門走了進去。。。\n", me);
me->move("/open/soldier/room/r22.c");
return 1;      
 }
              
   
  
  
  
