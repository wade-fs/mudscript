
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "樹洞中");
  set( "build", 15 );
  set ("long", @LONG
走入洞中，樹洞的上方微微的透出幾絲的光線，洞中沉浸著一股
迷濛的氣息，歷經千年以上的歲月方有此樹的出現，而這洞的成形也
少說幾百年了，樹洞的中心地帶還透出一股奇異的光茫，原來是一把
純金的劍(sword)插在上面。
LONG);
  set("exits", ([ /* sizeof() == 4 */
    "out"       : __DIR__"mon25",
  ]));
  set("item_desc",(["sword":
    "好奇的你走上前一看，是一把純金的劍，你的臉上瞬時露出貪心神色
的，你不禁想要將他拔出(pull)，但是怕誤觸機關的你，還是得小心
翼翼的在劍(sword)的四周特別的搜尋(specialsearch)一番。\n",
  ]));
  set("no_fight", 1);
  setup();
}

void init()
{
  add_action("search_sword", "specialsearch");
  add_action("pull_sword","pull");
}

int search_sword(string arg)
{
  object me = this_player();
  object room = environment(me);

  if(!arg)
    return notify_fail("你找來找去就是找不到你想要的東西!!\n");

  if( arg == "sword" )
  {
    if( room->query_temp("mon/sword") )
      return notify_fail("黃金劍已經消失，只剩一道劍的光影停留在原處。\n");

    if( (this_player()->query("combat_exp",1) < 1000000) )
      return notify_fail("也許\是你的歷練不足找不出劍的真正的位置。\n");

    if( room->query_temp("mon/search") == 1 )
      return notify_fail("一道朦朧的光茫，若隱若現，讓你看不真眼前的一切。\n");

//    message_vision(HIY"一陣低沉的輕鳴，黃金劍竟騰空而起，靜靜的懸在半空中。\n"NOR,me);
    write(HIY"一陣低沉的輕鳴，黃金劍竟騰空而起，靜靜的懸在半空中。\n"NOR);
    say(HIY"一陣低沉的輕鳴，黃金劍竟騰空而起，靜靜的懸在半空中。\n"NOR,environment(me), me);
    room->set_temp("mon/search",1);
    return 1;
  }
  return 0;
}

int pull_sword(string arg)
{
  object me = this_player();
  object room = environment(me);

  if(!arg)
    return notify_fail("你想拔什麼東西呀？？\n");

  if( arg == "sword" )
  {
    if( room->query_temp("mon/sword")==1 )
      return notify_fail("黃金劍已經消失，只剩一道劍的光影停留在原處。\n");

    if( !room->query_temp("mon/search") )
      return notify_fail("未經一番細細搜尋，使你猶豫了一下不敢冒然拔取!!\n");

//    message_vision(HIY"黃金劍發出一道耀眼的光茫後，竟然消失在你手中，而你的身形卻慢慢消失。\n"NOR,me);
    write(HIY"黃金劍發出一道耀眼的光茫後，竟然消失在你手中，而你的身形卻慢慢消失。\n"NOR);
    say(HIY"黃金劍發出一道耀眼的光茫後，竟然消失在"+HIY+me->name()+HIY"手中，而"+HIY+me->name()+HIY"的身形卻慢慢消失。\n"NOR,environment(me), me);
    tell_object(users(),HIW"一道白色的光芒直透天際，長白山的上空突然妖氣瀰漫，一個不祥的預兆湧上你心頭。\n"NOR);

    room->delete_temp("mon/search");
    room->set_temp("mon/sword",1);

    set("exits",([
      "enter" :__DIR__"mon59",
      "out"   :__DIR__"mon25",
    ]));

    call_out("close",720,room);
    return 1;
  }
  return 0;
}

int close(object room)
{
//  object me = this_player();
  object ob=this_object();
//  message_vision(YEL"光芒散去，眼前的入口又再度閉合消失了。\n"NOR,this_object());
  write(YEL"光芒散去，眼前的入口又再度閉合消失了。\n"NOR);
//  say(YEL"光芒散去，眼前的入口又再度閉合消失了。\n"NOR,environment(ob), ob);
  delete("exits/enter");
  room->delete_temp("mon/sword");
  return 1;
}
