// Room: /u/o/onion/room/hell.c

inherit ROOM;

void create()
{
	set("short", "地牢");
	set("long", @LONG
一座暗無天日的地牢,只有一點微弱的光線由牆角縫滲透進來,勉強可以分辨四周的
景物,整個牆壁是由堅硬的花崗石所築成,憑你的功力連挖點灰下來都不可能,硬想破牆
而出更是難如登天.想到自己要被困在這兒,不能去玩MUD,就覺得欲哭無淚,～哇～....

LONG
	);
        set("item_desc", ([
	"corner" :
"你睜大雙眼,仔細的往角落瞧,可是實在是太暗了,什麼都看不到咧...\n",	
        "plate" : 
"上頭似乎刻著一些甲骨文,憑著你優異的國學知識,你辨識出這些句子的意思是 :\n"+
"\n			IloveOnion\n\n"+
"疑..難道這就是密碼?\n"
	]));
	
	setup();
}

        void init()
        {
        	add_action("do_search","search");
                add_action("do_say","'");
                add_action("do_say","say");
        }
        
        int do_say(string str)
        {
        	if (str!="IloveOnion")
        	return 0;
        	else
        	{
        	write("恭喜你!!你答對了password,可以出去了.\n");
        	tell_room(environment(this_player()),
        	(string)this_player()->query("name")+
        	"忽然消失不見了,哇...沒帶我出去...\n",
                ({this_object(),this_player()}));
                this_player()->move(__DIR__"room3");
                write("碰～的一聲,你終於掉到地上了,疑...這不是原本的地方嗎?\n");
                tell_room(environment(this_player()),"碰～的一聲,你看到"+
                (string)this_player()->query("name")+"不知道從那掉了下來...\n",
                ({this_object(),this_player()}));
        	return 1;
        	}
        }	
        int do_search(string str)
        {
        	if (str!="corner")
        	{
        	write("你閒著無聊到處摸一摸...\n"+
       		      "嚇!!一隻死貓從角落(corner)跑出來\n");
		return 1;
		}
		else
		{
		write(
"角落裡似乎有一塊石板(plate)凹凹凸凸的,和其他牆壁特別不一樣,難道這是機關?\n");
		return 1;
		}
       	}         
