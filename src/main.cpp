#include <Geode/modify/EffectGameObject.hpp>

using namespace geode::prelude;

class $modify(MyEffectGameObject, EffectGameObject) {
	void triggerObject(GJBaseGameLayer* gjbgl, int p1, const gd::vector<int>* p2) {
		EffectGameObject::triggerObject(gjbgl, p1, p2);
		if (!gjbgl->m_endPortal || gjbgl->m_groups.empty() || this->m_objectID != 1931 || gjbgl != PlayLayer::get() || this->m_targetGroupID < 1 || gjbgl->m_isPlatformer || !gjbgl->m_level || gjbgl->m_level->isPlatformer()) return;
		CCArray* robWhatTheFuck = gjbgl->m_groups.at(this->m_targetGroupID);
		if (!robWhatTheFuck || robWhatTheFuck->count() != 1) return;
		gjbgl->m_endPortal->setPosition(static_cast<GameObject*>(robWhatTheFuck->objectAtIndex(0))->getRealPosition());
		gjbgl->m_endPortal->updateEndPos(true);
		gjbgl->m_endPortal->setVisible(true);
	}
};