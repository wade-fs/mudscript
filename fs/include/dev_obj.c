// by frequency 2003 10/20
#include <ansi.h>
void init0()
{
	object obj,me;
	string *msg,att,my_family;
	int *a,level,i,value,low;
	float high;
	obj = this_object();
	me = this_player();
        my_family = me->query("family/family_name");

	a = ({
	   	me->query("dev_obj/fire"),
                me->query("dev_obj/ice"),
                me->query("dev_obj/water"),
                me->query("dev_obj/ground"),
                me->query("dev_obj/wind"),
                me->query("dev_obj/thunder"),
                me->query("dev_obj/dark"),
                me->query("dev_obj/saint"),
	     });
	for(i=1;i<sizeof(a);i++)  //找出最高屬性值
	{
	 value = a[0];
	 if(a[i] > a[0])
	 {
	  value = a[i];
	  a[i] = a[0];
	  a[0] = value;	
	 }	
	}

//以下找出最突出屬性的所屬level
        low = 100;
	if(value > 31600)  level = 7;
	else if(value <= low) level = 0;
	else for(i=1;i<7;i++)                      //level 0 為           value <= 100
	{                                          //level 1 為     100 < value <= 600
	  high = low + pow(2,(i-1))*500;           //level 2 為     600 < value <= 1600
	  if(value <= high && value > low)         //level 3 為    1600 < value <= 3600
	  {                                        //level 4 為    3600 < value <= 7600
	    level = i;                             //level 5 為    7600 < value <= 15600
            break;                                 //level 6 為   15600 < value <= 31600
	  }                                        //level 7 為   31600 < value
	  low = high;
	}
	
	if(value == me->query("dev_obj/fire"))   //以下找出最突出的屬性
	 {
	   att = "fire";
	 }else if(value == me->query("dev_obj/ice"))
	 {
	   att = "ice";
	 }else if(value == me->query("dev_obj/water"))
	 {
	   att = "water";
	 }else if(value == me->query("dev_obj/ground"))
	 {
	   att = "ground";
	 }else if(value == me->query("dev_obj/wind"))
	 {
	   att = "wind";
	 }else if(value == me->query("dev_obj/thunder"))
	 {
	   att = "thunder";
	 }else if(value == me->query("dev_obj/dark"))
	 {
	   att = "dark";
	 }else if(value == me->query("dev_obj/saint"))
	 {
	   att = "saint";
	 }
	 
	 if(att == "fire" && level > 0)   //以下設定該屬性之形容語
	 {
	   obj->set("attribute","fire");
	   obj->set("dev_level",level);
	   msg = ({
	   	MAG"初陽"HIM"拂",
                RED"炬燃"HIR"灼",
                HIM"幟焰"MAG"燃",
                HIR"星火"RED"焚",
                HIY"焰靈"HIW"閃",
                HIW"融岩"HIC"裂",
                HIW"極"HIY"焰"HIM"‧"HIR"燎原火"NOR,
	   	   });
	   obj->set("name",msg[level-1]+obj->query("original_name"));	   
	   if(level < 3)           //裝卸敘述
	    {
	      obj->set("wmsg",YEL"陣陣高溫"NOR);
	      obj->set("uwmsg",YEL"高溫"NOR);
	      obj->set("amsg",obj->query("name")+""HIM"燃起一道烈焰，幟熱的高溫直逼強敵。\n"NOR);
	    }else if(level > 6)
	           {
	             obj->set("wmsg",HIW"驚人的陽炎幟焰"NOR);
	             obj->set("uwmsg",HIR"火光"NOR);
	             obj->set("amsg",obj->query("name")+""HIW"突然放出一道白光，驚人的幟焰四處亂竄，如火浪般舖天蓋\地而來。\n"NOR);
	           }else{
	                  obj->set("wmsg",HIR"幟熱焚風"NOR);
	                  obj->set("uwmsg",HIR"焚風"NOR);
	                  obj->set("amsg",obj->query("name")+""HIR"紅光大盛，高熱的焚風瞬間已捲向敵人。\n"NOR);
	                 }
	 }else if(att == "ice" && level > 0)
	 {
	   obj->set("attribute","ice");
	   obj->set("dev_level",level);
	   msg = ({
	   	HIC"冰結"HIB"霜",
                GRN"雪凝"HIC"冰",
                HIG"霜雹"HIW"雪",
                HIW"寒光"HIY"閃",
                HIB"凍氣"HIW"凝",
                HIW"冰封"HIM"絕",
                HIB"暴"HIC"雪"HIY"‧"HIW"南極光"NOR,
	   	   });
	   obj->set("name",msg[level-1]+obj->query("original_name"));	   
	   if(level < 3)           //裝卸敘述
	    {
	      obj->set("wmsg",HIB"一股涼意"NOR);
	      obj->set("uwmsg",HIB"涼意"NOR);
	      obj->set("amsg",obj->query("name")+""HIB"一揮之下，一股寒風拂過當場，冷得人直打哆嗦。\n"NOR);
	    }else if(level > 6)
	           {
	             obj->set("wmsg",HIW"驚人的凜冽凍氣"NOR);
	             obj->set("uwmsg",HIW"凍氣"NOR);
	             obj->set("amsg",obj->query("name")+""HIW"散發出驚人的凜冽凍氣，在這凍氣之下所有生命即將停止活動。\n"NOR);
	           }else{
	                  obj->set("wmsg",HIC"陣陣寒氣"NOR);
	                  obj->set("uwmsg",HIC"寒氣"NOR);
	                  obj->set("amsg",obj->query("name")+""HIC"的玄冰奇能引發一招『冰石亂墜』，無數冰雹急速降下。\n"NOR);
	                 }
	 }else if(att == "water" && level > 0)
	 {
	   obj->set("attribute","water");
	   obj->set("dev_level",level);
	   msg = ({
                HIG"春雨"HIC"飄",
                YEL"夏雨"HIC"襲",
                HIG"潺溪"HIB"流",
                HIW"飛瀑"HIB"落",
                HIB"潮汐"HIW"湧",
                HIC"巨浪"HIW"捲",
                HIC"水渰"HIB"‧"HIW"海嘯"NOR,
	   	   });
	   obj->set("name",msg[level-1]+obj->query("original_name"));	   
	   if(level < 3)           //裝卸敘述
	    {
	      obj->set("wmsg",HIB"一股水氣"NOR);
	      obj->set("uwmsg",HIB"水氣"NOR);
	      obj->set("amsg",obj->query("name")+""HIB"散發出絲絲水氣，型成一層保護結界。\n"NOR);
	    }else if(level > 6)
	           {
	             obj->set("wmsg",HIW"海嘯般的驚人水氣"NOR);
	             obj->set("uwmsg",HIW"巨浪之氣"NOR);
	             obj->set("amsg",obj->query("name")+""HIW"湧出的無盡巨浪，竟成為"HIC"海之結界"HIW"，在這障璧之下一切攻勢都將如入泥沼。\n"NOR);
	           }else{
	                  obj->set("wmsg",HIC"河海之氣"NOR);
	                  obj->set("uwmsg",HIC"水氣"NOR);
	                  obj->set("amsg",obj->query("name")+""HIC"的海之氣息立為ㄧ道水牆，阻絕了大部分的攻擊。\n"NOR);
	                 }
	 }else if(att == "ground" && level > 0)
	 {
	   obj->set("attribute","ground");
	   obj->set("dev_level",level);
	   msg = ({
	   	YEL"堅石"HIY"硬",
                RED"磐石"HIY"鎮",
                YEL"遠山"HIG"凝",
                YEL"土泥"HIG"阻",
                GRN"岩立"YEL"封",
                HIB"淵嶽"YEL"屹",
                HIY"百嶽地動震天"NOR,
	   	   });
	   obj->set("name",msg[level-1]+obj->query("original_name"));	   
	   if(level < 3)           //裝卸敘述
	    {
	      obj->set("wmsg",YEL"飛砂走石"NOR);
	      obj->set("uwmsg",YEL"砂石"NOR);
	    }else if(level > 6)
	           {
	             obj->set("wmsg",HIY"天下百嶽之氣"NOR);
	             obj->set("uwmsg",HIY"百嶽之氣"NOR);
	           }else{
	                  obj->set("wmsg",GRN"山靈之氣"NOR);
	                  obj->set("uwmsg",GRN"山靈之氣"NOR);
	                 }
	 }else if(att == "wind" && level > 0)
	 {
	   obj->set("attribute","wind");
	   obj->set("dev_level",level);
	   msg = ({
                HIG"疾風"HIC"奔",
                HIC"狂風"HIG"升",
          	HIC"暴風"HIG"嘯",
                HIB"颶風"HIW"捲",
                HIB"烈風"HIY"閃",
                HIG"天風"HIW"翔",
                HIC"神風"HIW"無限"HIB"真空"NOR,
	   	   });
	   obj->set("name",msg[level-1]+obj->query("original_name"));	   
	   if(level < 3)           //裝卸敘述
	    {
	      obj->set("wmsg",HIW"一襲清風吹過，流動的空氣"NOR);
	      obj->set("uwmsg",HIW"清風"NOR);
	    }else if(level > 6)
	           {
	             obj->set("wmsg",HIG"瞬時飛砂走石，無止境擴張的神風"NOR);
	             obj->set("uwmsg",HIG"神風"NOR);
	           }else{
	                  obj->set("wmsg",HIB"強風大起，高速流動的氣流"NOR);
	                  obj->set("uwmsg",HIB"強風"NOR);
	                 }
	 }else if(att == "thunder" && level > 0)
	 {
	   obj->set("attribute","thunder");
	   obj->set("dev_level",level);
	   msg = ({
	   	HIC"疾電"HIB"走",
                GRN"閃電"HIC"劈",
                HIG"春雷"HIW"暴",
                HIW"落雷"HIY"降",
                HIB"驚雷"HIW"閃",
                HIW"天雷"HIM"滅",
                  HIM"怒殛"HIY"‧"HIY"雷"HIR"鳴"HIW"閃"NOR,
	   	   });
	   obj->set("name",msg[level-1]+obj->query("original_name"));	   
	   if(level < 3)           //裝卸敘述
	    {
	      obj->set("wmsg",HIY"麻刺電氣"NOR);
	      obj->set("uwmsg",HIY"電氣"NOR);
	      obj->set("amsg",obj->query("name")+""HIB"一揮之下，一股寒風拂過當場，冷得人直打哆嗦。\n"NOR);
	    }else if(level > 6)
	           {
	             obj->set("wmsg",HIM"毀天怒雷"NOR);
	             obj->set("uwmsg",HIM"怒雷"NOR);
	             obj->set("amsg",obj->query("name")+""HIW"散發出驚人的凜冽凍氣，在這凍氣之下所有生命即將停止活動。\n"NOR);
	           }else{
	                  obj->set("wmsg",HIW"高壓電流"NOR);
	                  obj->set("uwmsg",HIW"電流"NOR);
	                  obj->set("amsg",obj->query("name")+""HIC"的玄冰奇能引發一招『冰石亂墜』，無數冰雹急速降下。\n"NOR);
	                 }
	 }else if(att == "dark" && level > 0)
	 {
	   obj->set("attribute","dark");
	   obj->set("dev_level",level);
	   msg = ({
	   	HIR"血腥"HIM"凶"NOR,
                GRN"禁忌"HIB"殺"NOR,
                HIB"魅影"RED"冥"NOR,
                HIM"邪異"CYN"妖"NOR,
                MAG"滅世"YEL"暴"NOR,
                YEL"誅神"HIM"魔"NOR,
                YEL+HBMAG"聖刻"NOR""HIM"‧"BLK+HBRED"暗黑"NOR,
	   	   });
	   obj->set("name",msg[level-1]+obj->query("original_name"));	   
	   if(level < 3)           //裝卸敘述
	    {
	      obj->set("wmsg",HIB"一股血腥味"NOR);
	      obj->set("uwmsg",HIB"血氣"NOR);
	      obj->set("amsg",obj->query("name")+""RED"射出一股腥臭腐血，當者莫不噁心頭痛，上吐下瀉。\n"NOR);
	    }else if(level > 6)
	           {
	             obj->set("wmsg",HIM"無窮無盡的妖冥魔氣"NOR);
	             obj->set("uwmsg",HIM"妖氣"NOR);
	             obj->set("amsg",obj->query("name")+""HIM"爆發出難以想像的驚天妖氣，妖氣摧枯\拉朽般的瘋狂腐蝕一切。\n"NOR);
	           }else{
	                  obj->set("wmsg",HIG"陣陣邪氣"NOR);
	                  obj->set("uwmsg",HIG"邪異"NOR);
	                  obj->set("amsg",obj->query("name")+""GRN"散發出陣陣妖氣，見者莫不膽顫心驚，四肢無力。\n"NOR);
	                 }
	 }else if(att == "saint" && level > 0)
	 {
	   obj->set("attribute","saint");
	   obj->set("dev_level",level);
	   msg = ({
	   	HIW"虔誠"HIR"古"NOR,
                HIY"救世"HIW"英"NOR,
                HIR"榮耀"HIM"王"NOR,
                HIC"守護"HIG"神"NOR,
                HIY"英雄"CYN"霸"NOR,
                YEL"傳說"HIR"心"NOR,
                HIY+HBGRN"仙天"NOR""HIR"‧"HBMAG+HIW"皇"HIC"極"NOR,
	   	   });
	   obj->set("name",msg[level-1]+obj->query("original_name"));	   
	   if(level < 3)           //裝卸敘述
	    {
	      obj->set("wmsg",HIC"一股英氣"NOR);
	      obj->set("uwmsg",HIC"英芒"NOR);
	      obj->set("amsg",obj->query("name")+""CYN"傳來一股暖流，頓時令人滿面春風，心情愉快。\n"NOR);
	    }else if(level > 6)
	           {
	             obj->set("wmsg","無限的浩然正氣");
	             obj->set("uwmsg","正氣");
	             obj->set("amsg",obj->query("name")+""HIY"突然爆發出壓倒性的仙天正氣，浩然四射宛如神恩浩蕩。\n"NOR);
	           }else{
	                  obj->set("wmsg",HIM"陣陣仙氣"NOR);
	                  obj->set("uwmsg",HIM"仙氣"NOR);
	                  obj->set("amsg",obj->query("name")+""HIM"源源不絕的散發出仙氣，受者莫不精神大振。\n"NOR);
	                 }
	 }
	return ;
}
