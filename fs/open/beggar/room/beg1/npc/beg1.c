inherit NPC;
string do_ans();
void create()
{
    set_name("老乞丐", ({ "beggar" }) );
    set("gender", "男性" );
    set("age",45);
    set("str",35);
    set("cor",45);
    set("cps",25);
    set("int",15);
    set("long","他是一個身穿破爛衣裳的乞丐.\n");
    set("combat_exp",350);
    set("attitude", "peaceful");
    set("chat_chance", 50);
    set("chat_msg", ({
            "老乞丐說: 請你賞我一些「吃的東西」好嗎??\n",
        }) );
    set("inquiry",([
                    "吃的東西" : "喔..好餓喔!!我想吃「雞腿」",
                    "雞腿"     : "就平南城小販賣的那個雞腿嘛, 超好ㄘ!!",
                    "暗號" : (: do_ans :), 
        ]));

    set_skill("parry", 15);
    set_skill("dodge", 5);
    setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();

 }      

int accept_object(object me, object obj)
{
      if( obj->query("id") == "fried chicken leg" )
        {
          command("pat "+getuid(me));
          command("say 太好了, 你真是個好人, 為了報答你, 我教你丐幫入幫「暗號」。");
          me->add_temp("app_beggar",1);
        }
        else
        {
        command("say 我不想吃難吃的東西啦, 我要吃雞腿!!");
        }
        destruct(obj);
        return 1;
}
string do_ans()
{
        object me=this_player();
        if( me->query_temp("app_beggar")==1)
        {
          me->set_temp("can_say",1);
          return("丐幫入幫暗語室 -- 一乞成名天下知 --曉了吧。");
        }
        else
          return("你蕭效喔, 想當乞丐。");
}




