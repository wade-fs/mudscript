
inherit NPC;
string ask_tesin();
void create()
{
        set_name("地精", ({ "sprite" }) );
        set("title","魔界村居民");
	set("gender", "雄性" );
        set("age",132);
	set("long","他是魔界村的居民, 相傳是天地精氣生成的魔物.\n");
	set("combat_exp",1000);
	set("attitude", "peaceful");
        set("chat_chance", 25);
        set("chat_msg", ({
              (: this_object(),"random_move" :),
             "地精抬起了頭, 用大大的眼睛四周張望著.\n",
             "地精輕聲的對你呢喃了幾句話, 可是你聽不懂.\n",
             "地精張嘴微笑, 露出尖銳的牙齒.\n",
        }) );
        set("inquiry",([
         "龍鐵心" : (: ask_tesin:),
         ]));
	set_skill("parry", 20);
        set_skill("dodge", 20);
	setup();
        add_money("coin", 50);
         	
}
 string ask_tesin()
 {
if (!this_player()->query_temp("find_tesin3"))
  {
  this_player()->set_temp("find_tesin4",1);
  return ("龍鐵心?他早在十幾年前..就到炎龍谷去了.");
  }
else
  {
  this_player()->set_temp("find_tesin4",2);
  return ("龍鐵心?他早在十幾年前..就到炎龍谷去了.");
  }

}
