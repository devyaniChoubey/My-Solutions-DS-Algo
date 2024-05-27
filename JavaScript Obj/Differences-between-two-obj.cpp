https://leetcode.com/problems/differences-between-two-objects/editorial/

https://leetcode.com/problems/differences-between-two-objects/description/


/**
 * @param {Object|Array} obj1
 * @param {Object|Array} obj2
 * @return {Object|Array}
 */
function objDiff(obj1, obj2) {
    if(obj1 === obj2) return {};
    if(obj1 === null || obj2 === null) return [obj1, obj2];
    if(typeof obj1 !== 'object' || typeof obj2 !== 'object') return [obj1, obj2];
    if(Array.isArray(obj1) !== Array.isArray(obj2)) return [obj1, obj2];
    
    let returnObject = {};

    for(const key in obj1){
        if(key in obj2){
            let subDiff = objDiff(obj1[key], obj2[key]);
            if(Object.keys(subDiff).length > 0){
                returnObject[key] = subDiff;
            }
        }
    }

    return returnObject;
};