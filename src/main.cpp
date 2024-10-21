#include <_main.hpp>

#include <Geode/modify/PlayerObject.hpp>
class $modify(PlayerObjectExt, PlayerObject) {
	$override void updateRotation(float p0) {
		if ((m_isRobot or m_isSpider) and !m_isOnGround) {

			auto org_isSwing = m_isSwing;
			auto org_isBird = m_isBird;

			if (SETTING(bool, "Use bird rotation")) m_isBird = true;
			else m_isSwing = true;

			PlayerObject::updateRotation(p0 * SETTING(double, "Delta Multiplier"));

			m_isSwing = org_isSwing;
			m_isBird = org_isBird;

			return;
		};
		PlayerObject::updateRotation(p0);
	}
};