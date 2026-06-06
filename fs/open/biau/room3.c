// Room: /u/o/onion/room/w_room1.c

inherit ROOM;

void create()
{
	set("short", "鑣局內堂走廊");
	set("long", @LONG
走廊的燈火依然明亮,在兩旁還擺設了一些精美的花瓶,似乎價值不菲,空氣中也傳來
清淡的香味.你注意到瓶子上清一色插的都是純白的花,只有在角落的一個花瓶裡插著一朵
淡黃的茶花,有點兒奇怪...
    在走廊的兩旁各有一間客間.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guestroom1",
  "north" : __DIR__"guestroom0",
  "west" : __DIR__"room1",
  "east" : __DIR__"room4",
]));
        set("item_desc", ([ /* sizeof() == 1 */
          "bottle" : "    一個釉彩的花瓶,插上鮮花實在是相得亦彰,更添風采...\n"
          ]));
          
	set("valid_startroom", "1");

	setup();
}

void init()
{
      	        add_action("do_search","search");
        	add_action("do_move","move");
}
        
        int do_search(string str)
        {
        	
        	if(str!="bottle")
		{
        	write("你四處搜查,但是好像沒有可疑的地方...唉~~白費工夫\n");	
        	return 1;
        	}
        	else
        	{
        	write("經過一番查看,你發現這瓶子似乎可以移動(move).\n");
        	tell_room(environment(this_player()),(string)this_player()->query("name")+
      	        "專心的觀察著花瓶,你正起意想嚇嚇他時,他卻突然轉身對你詭異的一笑,\n"
      	        +"反而讓你自己嚇的半死...\n",({this_object(), this_player()}));              
      	        return 1;
      	        }
	}

	int do_move(string str)
	{
		if(str!="bottle")
		write("你在五鬼搬運嗎?在搬啥東東啊...\n");
		else
		{
		write("你慢慢的將花瓶移動開來,只聽到～咿～~的一聲...\n"
		"哇!!...你站的地板突然裂了一個大洞,你像自由落體般掉了下去...\n");
		tell_room(environment(this_player()),(string)this_player()->query("name")+
		"所站的地方裂了一個大洞,你看到他掉了下去之後,地板馬上恢復原狀."+
		"只聽見一陣陣有如殺豬的聲音隱隱約約的傳過來...\n",
		({this_object(),this_player()}));
                this_player()->reincarnate();
                this_player()->move(__DIR__"jail");
		write("碰～的一聲,你終於掉到地了...\n");
		tell_room(environment(this_player()),"碰～的一聲,你看到"+
		(string)this_player()->query("name")+"像死豬般的掉了下來...\n",
                ({this_object(),this_player()}));
		return 1;
		}
	}		
		     	      	           	
