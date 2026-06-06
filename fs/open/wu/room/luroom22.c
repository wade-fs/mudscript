// Room: /open/wu/room/luroom22.c
// 瀧山派的祠堂
// 加入解謎物件 by nike
//調整銀針門save_die解謎線索與調整判斷邏輯 by blazakira 2011/3/19

inherit ROOM;
void create ()
{
  set ("short", "祠堂");
  set ("long", @LONG
這是瀧山派的用來供奉祖先及歷代的掌門的祠堂，一進此地你就被此
地的莊嚴肅穆氣氛所攝，不敢做出輕率的舉動，前方的牆上掛者一幅幅的
畫，畫上的人物是瀧山派歷代的掌門。
　　上方有一匾額寫著【忠肝義膽、浩氣長存】八個字。
LONG);
  set("exits", ([ /* sizeof() == 1 */
    "north" : "/open/wu/room/luroom19",
  ]));
  set("light_up", 1);
  setup();
}

void init()
{
  add_action("do_search","search");
  add_action("do_turn","turn");
  add_action("do_look","l");
  add_action("do_look","look");
}

int do_look(string arg)
{
  object me = this_player();

  if(!arg || arg != "匾額") return 0;
  if(present("delfire-mark",me))
  {
    write("你看得出來是一位大師執筆，蒼勁有力的八個字顯示出他的內力雄厚。\n據傳是前代掌門重寫過，但你總覺得哪裡不對勁。\n");
    return 1;
  }
}

int do_search(string arg)
{
  object me = this_player();

  if(!arg || arg != "匾額") return 0;
  if(present("delfire-mark",me))
  {
    write("你翻了翻牆上的匾額，在匾額後頭發現了一個奇特的旋鈕！\n");
    me->set("doctor/find_botton",1);
    return 1;
  }
}

int do_turn(string arg)
{
  object me = this_player();

  if(!arg || arg != "旋鈕") return 0;
  if(present("delfire-mark",me) && me->query("doctor/find_botton") == 1)
  {
    me->delete("doctor/find_botton");
    write("你使勁的轉了轉旋紐...\n");
    write("你終於把旋紐給轉動了，旁邊竟露出了一扇暗門！\n");
    write("你走進暗門之內，發現竟然別有洞天！\n\n");
    me->move("/open/wu/room/pnxroom");
    return 1;
  }
}
