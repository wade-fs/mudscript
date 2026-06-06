// copy from /d/snow/npc/teacher.c
inherit NPC;

int a;
int b;
int in_toss;

void create()
{
	set_name("王凱", ({ "wang","wang kai","kai"}) );
	set("gender", "男性" );
	set("age", 43);
	set("int", 26);
        set("long","他正聚精會神的看著桌上那一個大碗公，嘴中念念有詞。你好奇
 的想知道爾J公裡到底是啥寶貝，走近一看，挖哩勒！竟然是西八剌。\n" );
        
        set("inquiry",([
        "禁地": "你是誰！禁地的事我一概不知，就算知道不會告訴你，你走吧。\n",
        "封印": "唉！別說那麼多討人厭的話題了，咱們玩兩把吧，你贏了，再來問
        	我也不遲啊。\n"]
        ) );
	
	set("combat_exp",1087);
        set("max_kee",500);
        set("max_gin",500);                        
	set("attitude", "peaceful");
	set_skill("unarmed",50);
	set_skill("parry",50);
	set_skill("force",50);
	setup();
}

init()
{
	add_action("play_dice","play");
	add_action("toss_dice","toss");
}


int play_dice(string str)
{

	if( str!="dice" ) {
		write("你要玩什麼？\n");
		return 1;
	}
	write("王凱道:你先來吧，請擲骰子\n");
	return 1;
}

int toss_dice(string str)
{
	if( str!="dice") {
		printf("你要玩什麼？\n");
		return 1;
	}
	if( in_toss ){
		printf("我正在跟別人玩，不要打攪我們！！\n");
		return 1;
	}

	a=random(5)+1;
	b=random(5)+1;
	message_vision("$N大喊︰嬤瞇八咪轟，天兵天將為我所用，西八辣！！\n", this_player());
	if( a > 3 ) {
	 message_vision("$N大笑 : 哈！哈！我擲到 "+a+" 點，看來你是兇多吉少！！ 該你了！\n", this_player());
	} else {
	 message_vision("$N垂頭喪氣的說 : 唉！唉！真是賽，竟然是 "+a+" 點,你可樂了吧！你擲吧！\n", this_player());
	}//end if_else
	remove_call_out("shou_turn");
	in_toss=1;
	call_out("shou_turn",2, this_player()->query("id"));
	return 1;
}

void shou_turn(string str)
{
        say("\n只見王凱以迅雷不及掩耳速度，將碗公在空中晃了兩圈，隨即定在桌上，大叫一聲『開』！！\n");
	if( b > a ){
		command("say " + sprintf("哈！小兄弟你輸了，我擲到 %d 點。\n", b));
	}
        else if( b==a){
		command("say " + sprintf("我也是擲到 %d 點，這盤咱們可是合局了。\n", b));
	}
	else {
		this_object()->add(str, 1);
		if(this_object()->query(str) != 3)
			command("say " + sprintf("真是背啊，竟是擲到 %d 點，算我倒楣，咱們再來兩把！！\n",b));
		else if(this_object()->query(str) == 3)
		{
			command("say " + sprintf("真是背啊，竟是擲到 %d 點，輸你三次!! 我就告訴你吧。\n",b));
			command("tell "+ str +" 當年祖師爺逍遙子用三樣法寶將他封印起來，祖師爺退休之後就把三樣寶物分別交給他三個大弟子保管，要解開天魔的封印，非要這三樣法寶同時施法，除此之外別無他法。\n"); 
			this_object()->delete(str);
		}
	}
	in_toss = 0;
}
