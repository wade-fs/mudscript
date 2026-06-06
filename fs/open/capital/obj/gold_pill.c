inherit ITEM;
void create()
{
      set_name("九轉金丹",({"gold_pill"}) );
      set_weight(100);
      if( clonep() )
           set_default_object(__FILE__);
      else {
           set("unit","顆");
           set("long","這是這是一顆非常珍貴的丹藥, 運用內\功\服\化(adhibit)後可以增加內力。\n");
           set("value",100000);
           }
      setup();
}

void init()
{
	add_action("do_adhibit","adhibit");
}

int do_adhibit(string str)
{
	object me=this_player();
	object ob=this_object();
	if( str != "gold_pill" )
        {
	write("服化什麼?\n");
        return 1;
	}
if(me->query("quest/catch_thief/gold_pill")==1)
{
write("你已經吃過了。\n");
return 1;
}
	  message_vision("$N將$n服下, 隨即坐下\運\功\。\n",me,ob);
	  write("你感覺到丹田一股熱氣緩緩上升, 這股熱氣隨著你的內力運行奇經八"+
	  "脈一周, 之後便消逝無蹤了。\n");
	  me->add("max_force",20);
          me->set("quest/catch_thief/gold_pill",1);
	  destruct(ob);
          return 1;
}
