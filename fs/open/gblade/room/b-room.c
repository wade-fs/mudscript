// Room: /u/w/wugi/b-room.c
inherit ROOM;
string search_shelf();
int i=1;
void create ()
{
  set ("short", "內書房");
  set ("long", @LONG
這兒鼎焚百合之香，瓶插長春之蕊，畫棟雕簷，珠簾繡幕，四周靜
悄悄的，無一人聲，你彷彿聽到自己的心跳聲，『噗通！噗通！』。四
周望去見有數十個書架（shelf），用封條封著。
通常這個地方只有門主跟他的家眷們可以自由進出，要是沒有什麼事情
的話你還是快出去吧！


LONG);

  set("item_desc", ([ /* sizeof() == 1 */
	"shelf" : "書架上擺\的都是有關金刀門歷史的書籍，讓一心以為可以從這裡找到武功\秘笈的你覺的有些失望 .
",
]));
  set("light_up", 1);
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"g3-7.c",
]));
  set("no_fight", 1);
  set("search_desc", ([ /* sizeof() == 1 */
  "shelf" : (: search_shelf :),
]));

  setup();
}
string search_shelf()
{
	if(i>0)
	{
	i=i-1;
	message_vision("$N在書架中找來找去 , 拿了一本書放入懷中 \n",this_player() );
	new("/open/gblade/obj/papyrus")->move(this_player());
	return "";
	}
if (this_player()->query_temp("shaswordtime")==1)
{
    message_vision("$N在書架中找來找去 , 摸出了一顆金法珠並收進口帶中 \n",this_player() );
    this_player()->set_temp("quests/findball1",1);
   new("/open/gsword/obj1/gball")->move(this_player());
    return "";
}
	message_vision("$N在書房中翻來覆去 , 結果什麼也沒發現 \n",this_player() );
	return "";
}
