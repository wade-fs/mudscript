inherit NPC;

void create()
{
         set_name("獵人阿三",({"hunter"}));
	set("long","一個從小在森林中長大的獵人,看他隻身空手,卻令森林中的猛獸如此
畏懼,難道他曾學過些武功\?\n");
	set("gender","男性");
	set("combat_exp",23590);
        set("attitude","heroism");
	set("force",500);
	set("max_force",500);
	set("force_factor",5);
        set("age",25);
        set("score",100);
        set("str", 50);
        set("cor", 30);
        set("per", 15);
        set("int", 15);
	set("cps", 30);
	set("con", 30);
        set("kar", 20);
   /*
	set("chat_chance",10);
	set("chat_msg",({
	"獵人阿三說:死老虎,看我不扒下你的皮當地毯.\n",
	"獵人阿三說:其實我最感興趣的還是那隻白老虎.\n"}));
      */
        set_skill("dodge",30);
        set_skill("unarmed",30);
        set_skill("parry",20);
       set_skill("snow-martial",30);
        map_skill("dodge", "snow-martial");
        map_skill("unarmed", "snow-martial");
	set("inquiry",([
	"白老虎": "前幾天我有看到一隻白老虎,可惜被它溜了,唉,身為一個獵人,畢生
最大的心願莫過於能得到白虎皮.\n",
	"白虎皮": "如果我能一睹白虎皮,三某死亦無憾.\n",
	]));
	setup();
}
	int accept_object(object who,object ob)
	{
	string ob_id;
	ob_id=ob->query("id");
	if(ob_id=="white tiger skin")
	{
	command("say 這這..我實在太高興了,你這個朋友我交定了,為了報答你的恩情
我告訴你一個秘密,在峭壁上的動穴裡,住著一位仙人,三某承蒙仙人指導了幾天,
因而身強力壯,受用無窮,你到洞穴中找找看(search hole),也許能有此機緣,得
遇高人.\n");
	}
	return 1;
	}
         
      
