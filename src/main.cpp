#include <_main.hpp>

//extra hardcode goes here

#include <Geode/modify/PlayerObject.hpp>
class $modify(PlayerObjectExt, PlayerObject) {
	$override void updateRotation(float p0) {
		if ((m_isRobot or m_isSpider or SETTING(bool, "For all game modes")) and !(m_isOnGround and !SETTING(bool, "Don't care if is On Ground"))) {

			auto wasSwing = m_isSwing;
			auto wasBird = m_isBird;

			if (SETTING(bool, "Use bird rotation")) m_isBird = true;
			else m_isSwing = true;

			PlayerObject::updateRotation(p0 * SETTING(double, "Delta Multiplier"));

			m_isSwing = wasSwing;
			m_isBird = wasBird;

			return;
		};
		PlayerObject::updateRotation(p0 * SETTING(double, "Global Delta Multiplier"));
	}
};
