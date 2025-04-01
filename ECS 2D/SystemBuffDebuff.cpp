#include "SystemBuffDebuff.h"
#include "ComponentBuffDebuff.h"
#include "ComponentHealth.h"
#include "ComponentStats.h"
#include "EffectDatabase.h"
#include <iostream>

SystemBuffDebuff::SystemBuffDebuff() {}

void SystemBuffDebuff::ApplyEffect(Entity* target, const std::string& effectId) {
    const EffectDefinition* def = EffectDatabase::Get().GetEffect(effectId);
    if (!def) return;

    auto* buff = target->GetComponent<ComponentBuffDebuff>();
    if (!buff) return;

    buff->AddEffect(def);

	std::cout << "[BuffDebuff] Effet appliqué : " << def->id << " à entity ID " << target->GetID() << std::endl;
}

void SystemBuffDebuff::Update(float dt, const std::vector<Entity*>& entities) {
    for (Entity* entity : entities) {
        auto* buff = entity->GetComponent<ComponentBuffDebuff>();
        if (!buff) continue;

        auto* health = entity->GetComponent<ComponentHealth>();
        auto* stats = entity->GetComponent<ComponentStats>();

        for (const AppliedEffect& effect : buff->GetActiveEffects()) {
            if (!effect.definition) continue;

            if (effect.definition->tickDamage > 0 && health) {
                health->TakeDamage(effect.definition->tickDamage);
                std::cout << "[BuffDebuff] " << effect.definition->id << " inflige "
                    << effect.definition->tickDamage << " dégâts à entity ID " << entity->GetID() << std::endl;
            }

            if (stats && !effect.definition->statModifiers.empty()) {
                for (const auto& it : effect.definition->statModifiers) {
                    stats->AddModifier(it.first, it.second);
                }
            }
        }

        buff->Tick();
    }
}
