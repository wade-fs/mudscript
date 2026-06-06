inherit ROOM;
void create ()
{
  set ("short", "佛堂");
  set ("long", @LONG

自從王元霸的獨子生了一場怪病後，王元霸的妻子就經常在這裡為他的兒
子禱告，佛堂的擺設相當的樸素，當中擺著一個神案，供奉一尊白玉雕成
的觀音像，法像莊嚴，兩旁擺著一些法器，不時還飄來一些檀香的香氣。
你可以在觀音大士面前祈禱(pray) , 消災減厄。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"g3-3.c",
]));
	set("item_desc",
	([ "statue"  :  "一尊白玉雕成的觀音像 \n" ]));
  set("light_up", 1);

  setup();
}
void init()
{
        add_action("do_pray","pray");
	add_action("do_search","search");
	add_action("do_move","move");
}


int do_pray(string arg )
{
	object ob;
	ob=this_player();
	if(ob->query("sen") > 50)
	{
   message_vision("$N誠心的向觀音像膜拜。....願上天寬恕我的殺業....\n",this_player());
	if(random(10)>1)
	{
	call_out("do_act1",3,ob);
	return 1;
	}
	call_out("do_act2",3,ob);
	return 1;
	} else
	message_vision("$N的精神不夠集中, 不足以感動觀音菩薩..\n", this_player());
	return 1;
}
int do_act1(object ob)
   {
     message_vision("$N彷彿聽到觀音大士正在說法....『爾時菩薩即從座起，偏袒右肩.....
$N覺的內心一片祥和 , 暴厲之氣大減。\n\n",ob);
	ob->add("bellicosity",-5);
	ob->add("sen",-50);
     return 1;
}
int do_act2(object ob)
{
       message_vision("$N沒聽到觀音說法卻聽魑魅魍魎的蠱惑之聲，不知不覺中殺氣騰騰。\n",ob);
       ob->add("bellicosity", 2);
      return 1;
   }


int do_search(string str)
{
	if(!str)
	{
	if(this_player()->query("lotch")<1)
	return 0;
	write("你仔仔細細的察看整個房間 , 發現觀音像似乎有些異樣 .\n");
	return 1;
	}
	if(str=="statue")
	{
	if(this_player()->query("lotch")<1)
	return 0;
	write("當你察看觀音像時 , 你的直覺告訴你 : 觀音像似乎可以移動 \n");
	this_player()->set_temp("can-move",1);
	return 1;
	}
return 0;
}
int do_move(string str)
{
	if(!str||str!="statue")
	return notify_fail("你要移動什麼 ?\n");
	if(!this_player()->query_temp("can-move") )
	return notify_fail("你不怕褻瀆了神祇 \n");
	message_vision("$N走到觀音像前 , 將神像輕輕移動\n",this_player() );
	message_vision("地上突然開了個大洞 ,$N往下掉了下去 !\n",this_player() );
	this_player()->delete_temp("can-move");
	this_player()->move("/open/gblade/room/p-room1");
	write("碰的一聲 , 你掉到了地下 \n");
	return 1;
}
