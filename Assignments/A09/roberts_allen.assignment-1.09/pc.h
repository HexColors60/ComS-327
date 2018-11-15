#ifndef PC_H
#define PC_H

#include <stdint.h>

#include "dims.h"
#include "character.h"
#include "dungeon.h"

// class pc : public character
// {
// public:
//   ~pc() {}
//   terrain_type known_terrain[DUNGEON_Y][DUNGEON_X];
//   uint8_t visible[DUNGEON_Y][DUNGEON_X];
// };

typedef enum equip_inv
{
  equip_inv_weapon,
  equip_inv_offhand,
  equip_inv_ranged,
  equip_inv_light,
  equip_inv_armor,
  equip_inv_helmet,
  equip_inv_cloak,
  equip_inv_gloves,
  equip_inv_boots,
  equip_inv_amulet,
  equip_inv_lring,
  equip_inv_rring,
  num_equip_inv
} equip_inv_t;

class pc : public character
{
private:
  void recalculate_speed();
  uint32_t has_open_inventory_slot();
  int32_t get_first_open_inventory_slot();
  object *from_pile(dungeon_t *d, pair_t pos);

public:
  terrain_type known_terrain[DUNGEON_Y][DUNGEON_X];
  unsigned char visible[DUNGEON_Y][DUNGEON_X];
  object *eq[num_equip_inv];
  object *in[INVENTORY_SIZE];

  uint32_t wear_in(uint32_t slot);
  uint32_t remove_eq(uint32_t slot);
  uint32_t drop_in(dungeon_t *d, uint32_t slot);
  uint32_t destroy_in(uint32_t slot);
  uint32_t pick_up(dungeon_t *d);
  pc();
  ~pc();
};

extern const char *equip_inv_name[num_equip_inv];

void pc_delete(pc *pc);
uint32_t pc_is_alive(dungeon *d);
void config_pc(dungeon *d);
uint32_t pc_next_pos(dungeon *d, pair_t dir);
void place_pc(dungeon *d);
uint32_t pc_in_room(dungeon *d, uint32_t room);
void pc_learn_terrain(pc *p, pair_t pos, terrain_type ter);
terrain_type pc_learned_terrain(pc *p, int16_t y, int16_t x);
void pc_init_known_terrain(pc *p);
void pc_observe_terrain(pc *p, dungeon *d);
int32_t is_illuminated(pc *p, int16_t y, int16_t x);
void pc_reset_visibility(pc *p);

#endif
