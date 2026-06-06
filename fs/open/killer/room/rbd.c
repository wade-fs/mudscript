// open/killer/room/rbd.c
inherit ROOM;
void create()
{
  set ("short", "密室");
  set ("long", @LONG
這是東瀛機關聖手--諸岡渡，所建造的超級地下水道。。
這是因為有許多的門派令人看守大門,使得殺手們無法順利進行暗殺行動。
以至於當年黑牙連第一代掌門人葉孤城，遠赴東洋聘請諸岡渡。
並且於富士山上，取得了富士山密草。據說在總壇的某處有密草的存在。
小渡率領殺手們費了幾十年,來建造這個地下水道,
如今此水道已成,但你卻不知道他是要通往那裡!!
LONG);
   set("exits", ([
// "east"   : __DIR__"rbde.c",
   "south"  : __DIR__"rbds.c",
   "up"     : __DIR__"rb.c",
  ]));
   set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  set("light_up", 1);
  setup();
} 

void init()
{
 add_action("do_search",({"search"}));
}

int do_search (string arg)
{
 object me,ob;
 
 me=this_player();
 
 if (arg)
 	return 0;
 if ( me->query_temp("rain_1") == 1)
 {
   if (me->query_temp("rain_3") != 1)
   {
      tell_object(me,"忽然，你眼前一花，一道人影出現在你眼前\n");
      tell_object(me,"此人張口說：聽說你最近，一直在找天魔解體大法？\n");
      tell_object(me,"我可以給你幫忙，不過，你先幫我送這一封信給莊靜柔\n");
      tell_object(me,"此人丟給你一封信，你眼前又一花，他又消失了\n");
      tell_object(me,"只留下一頭霧水的你，彷彿經歷了一場夢。\n");
      ob=new("/open/killer/obj/sorrylet.c");
      ob->move(me);
      me->set_temp("rain_2",1);
      return 1;
   }
   if (me->query_temp("rain_3") ==1)
   {
    message_vision("$N仔細的找了一下，發現了一個按鈕，按下之後，出現一條往下的通道。\n", me);
    set("exits/down", __DIR__"rourm.c");
    return 1;
   }
 }
 if ((me->query_temp("firstpart") == 5) || (me->query_temp("firstpart") == 11))
 {
      message_vision("$N在這裡瘋狂的叫喊柴榮，似乎想把死人都給吵醒\n", me);
      tell_object(me,"忽然，地下的機關突然打開，出現了一條往下的通道\n");
      me->set_temp("opendoor",1);
      //雖然都是往下，但是前往的房間不一樣
      set("exits/down", __DIR__"rourm2.c");
    return 1;
 }
 return 0;
}

int valid_leave(object me, string dir)
{
  if (dir != "down") 
  {
    this_object()->delete("exits/down");
    return 1;
  }
  //如果不是解rain而來，此temp不會為1
  //如果不是解dark-stpes而來，opendoor也不會是1
  //如果這兩個都沒有0->1，代表不是因為這兩件事情而來，所以不可以往下
  if ( !me->query_temp("rain_3") && !me->query_temp("opendoor"))
    return 0;
    this_object()->delete("exits/down");
  return 1;
}
