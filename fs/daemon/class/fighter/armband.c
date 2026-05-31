
// sun_armband.c

inherit EQUIP;

void create()
{
        set_name("[0;31m¶[1;31m§[0;31mª[1;31m¢[0;31mÁ[1;31mu[0;31mÀ[1;31mô[0m ",({"Sun Fire Armband","armband"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","¥Î¨ªåbª÷»s¦¨ªºÁuÀô, ¤W­±Æ^¦³¤@Áû¶§ª¢¥Û, ¬Û¶Ç°ß¦³®±¸t¤~¦³¸ê®æ°tÀ¹¦¹ÁuÀô");
        set("unit","­Ó");
        set("value",1750);
        set("material","crimsonsteel");
        set("armor_type","armbands");
        set("armor_prop/armor", 8);
        set("armor_prop/unarmed", 10);
        set("armor_prop/force", 10);
        set("armor_prop/dodge", 10);
        set("need_exp",90000);    // by frequency
        }
        setup();
}
int wear()  //fix by frequency
{
 if(!this_player()) return 1;
            if( this_player()->query("max_force") < 900 )
            return notify_fail("»Õ¤U¤º¤O¤£°÷²`«p¡AµLªk§Ô¨ü¶§ª¢°ª¼ö¡C\n");
            if( this_player()->query("combat_exp") < 90000 )
            return notify_fail("¤Ö¨Ó!!´N¾Ì§A¤]¥´±o¹L¥ô´Â¶§¡H\n");
  ::wear();
 return 1;
}
