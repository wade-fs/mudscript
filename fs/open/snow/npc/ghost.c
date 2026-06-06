// woodcutter.c

inherit "/std/char/new_npc";

void create()
{
          set_name("怨靈",({"ghost"}));
          set("short","          ");
	set("gender", "男性" );
	set("age", 26);
	set("long", "你看到一個粗壯的大漢﹐身上穿著普通樵夫的衣服。\n");
	set("combat_exp", 220);

	set("str", 30);
         set("chat_chance",60);
          set("chat_msg",({
       (: command,"get all" :),
          "四周傳來陣陣怨靈的哭嚎聲，聲聲震耳。\n"
	}) );
	set("env/wimpy", 10);
	setup();
}
