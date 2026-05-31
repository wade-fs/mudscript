// shield.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;
	if( query("armor_prop/armor") > PROP_SHIELD )
	  set("armor_prop/armor", PROP_SHIELD);
	set("armor_type", TYPE_SHIELD);
	if( !query("armor_apply/dodge") && weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}
int wear()
{
  object owner;
  string type;
  if(!environment()) return 0;
  // Only character object can wear armors.
  if( !(owner = environment())->is_character() ) return 0;
  type = query("armor_type");

  if(userp(owner) 
      && owner->query_temp("third_weapon") )
  {
    write("你必需放下第三把武器。\n");
    return 0;
  }

  return ::wear();
}
