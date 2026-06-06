

//老者

inherit NPC;
string do_act();
string do_acc();
 int i=0;

void create()
{
        set_name("老者",({"older"}));
        set("gender","男性");
        set("age",50);
        set("class","blademan");
        set("str",10);
   set("long","一位看起來很憔悴的老人。 .\n");
        set("chat_chance",10);
        set("chat_msg",({
                "老者說:我的兒子怎麼還不回來?\n"
                }));
      set("inquiry",([
 "兒子" : (:do_act:) ,
              "炎龍谷" : (:do_acc:),
        ]));
        add_action("do_act","act");
        add_action("do_acc","acc");
        set("combat_exp",1000000);
        setup();
        add_money("silver",1);
}
int accept_fight(object who)
{
 return notify_fail("老者說:我已經老了，動不了了。\n");
}
void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting()) 

        {
        remove_call_out("greeting");
        call_out("greeting",2,obj);
        add_action("do_say","say");
        }
}
void greeting(object ob)
{
        command("think ");
}
  string do_act()
{
        command("say 我的兒子幾年前到炎龍谷後就一去不回了。 ");
        command("say 有誰能幫我找回來呢?");
        command("say 如果能找回來，一定有報酬。");
        command("say 他的名字是：楊格。");
        this_player()->set_temp("can_say",1);
        return "可以嗎?";
 }
   void do_say(string str)
{
  object me;
  me = this_player();
  if(this_player()->query_temp("can_say")==1)
   {
  if(str=="可以")
  {
   //message_vision("$N說道 : 可以 \n",me);
        new("/u/p/poloer/dragon/obj/letter")->move(this_player());
   message_vision("老者說:那就麻煩了。\n",me);
   if(this_player()->query("gender")=="男性")
  command("say 那我交給你一封信 , 如果遇見我兒,請勿必交給他。");
  if(this_player()->query("gender")=="女性")
   command("say 那我交給妳一封信 , 如果遇見我兒,請勿必交給他。");
  command("smile");
  this_player()->delete_temp("can_say",1);
        }
  
  }
}

string do_acc()
{
object me;
me = this_player();
        command("say 那裡是個很恐怖的地方，尤其是那隻炎龍。 ");
        command("say 炎龍和它的子孫幾年前把一座村落給佔據了。");
        command("say 我的兒子剛好到那去作生意，就.......。");
        command("say 閒雜人等還是不要去的好。");
                command("say 不過聽說把炎龍殺死後，......啊!我不能在說了。");
        return "想去嗎?";
}


void heart_beat()
{
        if( random(5) < 2 ){
        if(!is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
            if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
                           }
        }
        :: heart_beat();
}       
