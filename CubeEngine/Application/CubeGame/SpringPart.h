#pragma once
#include "GameConstraint.h"
#include "GraphNode.h"

namespace tzw
{
class vec3;
class Drawable3D;
class BlockPart;
struct Attachment;
class Physics6DofSpringConstraint;
class SpringPart : public GameConstraint
{
public:
	SpringPart(std::string itemName);
	Physics6DofSpringConstraint * m_constrain;
	void enablePhysics(bool isEnable) override;
	void dump(rapidjson::Value& partData, rapidjson::Document::AllocatorType& allocator) override;
	Attachment* getFirstAttachment() override;
	Attachment * getAttachment(int index) override;
	int getAttachmentCount() override;
	float getStiffness() const;
	float getDamping() const;
	void setStiffness(float stiffness);
	void setDamping(float damping);
	void generateName() override;
	virtual ~SpringPart();
	void drawInspect() override;
	bool isNeedDrawInspect() override;
	void updateConstraintState() override;
	void AddOnVehicle(Vehicle * vehicle) override;
private:
	void findPiovtAndAxis(Attachment * attach, vec3 hingeDir, vec3 & pivot, vec3 & asix);
	float m_stiffness;
	float m_damping;

};
}
