// Room: /open/wu/room/school17
inherit ROOM;

string do_corner();
void create ()
{
  set ("short", "青雲居");
  set ("long", @LONG
走進這裡，你看到有個人正埋首書堆，完全無視你的到來。你看到這房間
到處都堆滿了書籍，連一張床也沒有，仔細一瞧，你可以在牆角發現一條睡覺
用的被子，被子旁邊還有一個咬剩的包子，以及一瓶半滿的清水。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"school16",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/trainer2.c" : 1,
]));

  set("item_desc", ([ /* sizeof() == 1 */
"corner": "牆角堆滿雜亂無章的東西, 一看就不想去翻。\n",

  ]));
  set("search_desc",([
  "corner" : (: do_corner :),
  ]));

  set("light_up", 1);

  setup();
}

string do_corner()
{
        
        object me=this_player();
//      if(me->query_temp("thief") == 8)
  if (me->query_temp("get_book") == 0)
{
          write("你狠下心來整理一下這些雜物......\n\n砰..有一件東西從棉被中掉了出來....\n");
        
          new("/open/wu/obj/haoforce_book")->move("/open/wu/room/school17");
  me->set_temp("get_book",1);
          
/*        tell_room(environment(me),"啊~~~~~~~~的一聲慘叫, "+me->query("name")+
          me->move(CAPITAL_ROOM"q0");
          return("咚的一聲..你掉到了地上。\n");
*/
        }
        else
           return("你找了老半天，可是看不出有任何特殊之處。\n");
}
