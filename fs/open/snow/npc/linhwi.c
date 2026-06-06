#include <ansi.h>

inherit NPC;

string identy()
{
	object ob;
	if( present("lin sword",this_player()) )
		return "你身上的那把劍就是憑證﹗\n";
	ob = new("/open/snow/obj/lin_sword");
	ob->move(this_player());
	tell_object(this_player(),"劉玲慧給你一把劍。\n");
	this_player()->set("quests/to-kill-0",1);
	return "這本劍是我平時隨身攜帶的﹐拿給他看他會相信的。\n";
}
void create()
{
        set_name("劉玲慧", ({ "liu linhwi", "hall", "linhwi" }) );
        set("long",
             "她是掌門的女兒,由於誤觸門規,還是被掌門關在禁閉室裡面。\n");
        set("attitude", "heroism");
        set("gender", "女性" );
        create_family("雪蒼派",5,"弟子");
        set("age", 20);
        set("str", 20);
        set("cor", 20);
        set("cps", 20);
        set("per", 30);
        set("max_force", 300);
        set("force", 300);
        set("force_factor",5);

	set("combat_exp", 24637);

        set("chat_chance", 3);
        set("chat_msg", ({
                "劉玲慧說:唉～真是無聊...\n",
                "劉玲慧說:爹爹也真是太兇了,不小心犯錯就把我關在這裡!\n",
                "劉玲慧說:真羨慕你可以自由的活動...\n",
        }) );


	set("force",300);
	set("max_force",300);
        set_skill("unarmed", 35);
        set_skill("force", 40);
        set_skill("literate", 35);
        set_skill("snowforce", 35);
        set_skill("parry", 35);
        set_skill("dodge", 35);
         set_skill("snow-martial", 20);
        map_skill("force", "snowforce");
	set_skill("black-steps",30);
	map_skill("dodge","black-steps");
         map_skill("unarmed", "snow-martial");
        set("inquiry",([
           "劉全書":   "他就是我爹爹。\n",
           "天邪石":   "相傳天邪石有一祕密,詳細內容我也不清楚,爹爹識它為至尊的寶物,我就是因為天邪石才被爹爹罰關在此處。\n",
	"密室": "聽爹爹說過﹐在後山的密室裡好像關著一個人。\n",
	"如何進入密室" : "這個我也不太清楚﹐不過好像聽說要寫字在牆上的石版上。\n",
	"黑仙羅漢" : "這個人有聽我爹爹提過﹐他好像跟我爹爹之間有些什麼特別的關係似的。",
	"劉全書與黑仙羅漢" : "這個是我爹爹的密秘﹐我問過他好幾次﹐他都不說。",
	"密秘" : "要我爹爹說出他的密秘很難啦﹐除非 .....\n",
	"除非" : "我幹嘛平白無故幫你﹐除非你幫我把雲哥哥帶來見我。\n",
	"憑證" : (: identy :),
           ]));

        setup();

        carry_object("/obj/cloth")->wear();
}
int ok()
{
	if( this_player()->query("quests/to-kill-0") != 1 ) return 0;
	command("say 雲哥哥 ....");
	command("smile");
	command("smile "+this_player()->query("id"));
	command("say 只要跟我爹爹提到「玉門關」一室﹐我爹爹就會毫無招架之地。");
	this_player()->set("quests/to-kill-1",1);
}
void init()
{
	object ob;
	object env = environment( this_object() );
	if( (ob = present("dugur",env)) && ob->name() == "獨孤雲" )
		call_out("ok",1);
}
