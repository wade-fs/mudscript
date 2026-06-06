inherit NPC;
string do_give();
int i=1;

string do_ask (object me);

void create()
{
        set_name("紀文鳳", ({ "wen fun","fun" }) );
        set("long", "
她是金刀門門主王元霸的妻子，跟王元霸是青梅竹馬，也同是武林世家出
身，早年以一對鴛鴦刀另令黑道人士喪膽。
看她肌膚微豐，合中身材，腮凝新荔，鼻膩鵝脂，溫柔沈默，觀之可親。
\n");
        
        set("nickname","寶刀柔情");  

        set("age", 45);
        set("int", 26);
        set("cps", 22);
        set("str", 27);
        set("cor", 27);
        set("spi", 24);
        set("con", 30);
        set("kar", 28);
        set("per", 30);
        set( "force_factor", 10 );
        set( "score", 90 );
        set("combat_exp", 400000);
        set("force",1500);
        set("max_force",1500);
        set_skill("blade", 60);
        set_skill("dodge", 75);
        set_skill("parry", 60);
        set_skill("force", 58);
        set_skill("gold-blade",60);
        set_skill("sixforce",53);
        set_skill("fly-steps",64);
        map_skill("force", "sixforce");
        map_skill("blade", "gold-blade");
        map_skill("dodge", "fly-steps");

        set("race", "人類");
        set( "gender", "女性");

        set("limbs", ({ "頭部",  "雙腳", "雙手", "背部" ,"腹部","腰部"}) );
    
        set("attitude", "peaceful");

        set("chat_chance", 6);
        set("chat_msg", ({
        "紀文鳳跪在觀音大士法像前低聲祈禱。\n",
        "紀文鳳用略帶悲傷的聲音嘆道：『唉！萬一雲兒的病治不好那可怎麼辦才好。』\n",
        }) );
        set("chat_chance_combat",10);
        set("chat_msg_combat",({
        "紀文鳳道：『莊嚴佛堂豈容你無知小輩作亂。』\n",
        "紀文鳳大喝：『無知小輩我替上天來懲罰你。』\n",
        "紀文鳳嘆了口氣；『唉！你不是我的對手！』\n",
        }));
        set("inquiry",([
        "兒子" : "唉！我那可憐的兒子，看他發病時的痛苦樣子實在很不忍心。\n",
        "病" :   "最近有一位西域來的聖僧他開了一藥方說可以治好我雲兒的病，也不知是真是假。\n",
        "藥方" : "上面列了一堆奇奇怪怪的藥材，大概要到皇城裡的藥材鋪裡才找得到吧！\n",
        "藥材鋪" : "你要幫我去抓藥嗎？不然問那麼多做什麼呢？\n",
        "無名" : "你是說我們金刀門請來的那個泥水匠阿？\n",
        "抓藥" : (:do_give:)
        
        ]));        
  
        setup();

        carry_object("/u/l/longhair/gold_blade/obj/mandarin_duck-blade.c")->wield();
        add_money("gold",15);
}

string do_give()
{
        if(this_player()->query_temp("magistral"))
        return "藥材呢？";
        if(i==0)
        return "我已經請人幫我跑腿去配藥了。";
        new("/open/gblade/obj/magistral.c")->move(this_player());
        message_vision("紀文鳳從懷中拿出一張藥方籤 , 交給$N \n",this_player());
        i=i-1;
        this_player()->set_temp("magistral",1);
}

